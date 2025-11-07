#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define PORT 2030
#define MAX_CLIENTS 10
#define MAX_INPUT_SIZE 512
#define SHM_KEY 0x1234

// ----- Shared Memory Chat Structure -----
typedef struct {
    char chat_log[20][MAX_INPUT_SIZE];
    int msg_count;
} shared_chat_t;

// ----- Message Queue structure -----
struct msgbuf {
    long msg_type;
    char msg_text[MAX_INPUT_SIZE];
};

int main() {
    int server_fd, client_fd, max_sd, sd, i, shmid;
    int client_socket[MAX_CLIENTS] = {0};
    struct sockaddr_in address;
    char buffer[MAX_INPUT_SIZE];
    fd_set readfds;
    int activity, valread;
    socklen_t addrlen = sizeof(address);

    // ---------- Create shared memory ----------
    shmid = shmget(SHM_KEY, sizeof(shared_chat_t), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    shared_chat_t *chat = (shared_chat_t *)shmat(shmid, NULL, 0);
    if (chat == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    chat->msg_count = 0;

    // ---------- Create message queue ----------
    int msgid = msgget(SHM_KEY, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("msgget");
        exit(1);
    }

    // ---------- Create socket ----------
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created\n");

    // Setup address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Binding successful\n");

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d...\n", PORT);

    // ---------- Main loop ----------
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        // Add client sockets
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];
            if (sd > 0)
                FD_SET(sd, &readfds);
            if (sd > max_sd)
                max_sd = sd;
        }

        // Wait for activity
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("select error");
            continue;
        }

        // New connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
                perror("accept");
                continue;
            }

            printf("New connection, socket fd=%d, IP=%s, PORT=%d\n",
                   client_fd, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = client_fd;
                    break;
                }
            }
        }

        // Handle client messages
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];
            if (FD_ISSET(sd, &readfds)) {
                memset(buffer, 0, MAX_INPUT_SIZE);
                valread = read(sd, buffer, MAX_INPUT_SIZE - 1);

                if (valread <= 0) {
                    // Client disconnected
                    getpeername(sd, (struct sockaddr*)&address, &addrlen);
                    printf("Client disconnected: %s:%d\n",
                           inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    client_socket[i] = 0;
                } else {
                    buffer[valread] = '\0';
                    printf("Client(%d): %s", sd, buffer);

                    // ---- Log to message queue (for logging only) ----
                    struct msgbuf message;
                    message.msg_type = 1;
                    snprintf(message.msg_text, MAX_INPUT_SIZE, "Client(fd=%d): %s", sd, buffer);
                    msgsnd(msgid, &message, sizeof(message.msg_text), 0);
		    msgrcv(msgid,&message,sizeof(message.msg_text),1,0);
                    // ---- Log to shared memory ----
                    if (chat->msg_count < 20) {
                        snprintf(chat->chat_log[chat->msg_count], MAX_INPUT_SIZE,
                                 "Client(fd=%d): %s", sd, message.msg_text);
                        chat->msg_count++;
                    } else {
                        // rotate messages if full
                        for (int j = 1; j < 20; j++)
                            strcpy(chat->chat_log[j - 1], chat->chat_log[j]);
                        snprintf(chat->chat_log[19], MAX_INPUT_SIZE,
                                 "Client(fd=%d): %s", sd, message.msg_text);
                    }


                    // ---- Print shared chat log ----
                    printf("---- Shared Chat Log ----\n");
                    for (int j = 0; j < chat->msg_count; j++)
                        printf("%d: %s", j + 1, chat->chat_log[j]);
                    printf("--------------------------\n");

                    // ---- Send server reply ----
                    printf("Server reply: ");
                    fflush(stdout);
                    fgets(buffer, sizeof(buffer), stdin);

                    write(sd, buffer, strlen(buffer));
                }
            }
        }
    }

    return 0;
}

