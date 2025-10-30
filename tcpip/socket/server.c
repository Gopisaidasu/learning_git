#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 2030
#define MAX_CLIENTS 10
#define MAX_INPUT_SIZE 256

int main() {
    int server_fd, client_fd, max_sd, sd,i;
    int client_socket[MAX_CLIENTS]={0};
    struct sockaddr_in address;
    char buffer[MAX_INPUT_SIZE];
    fd_set readfds;
    int activity, valread;
    socklen_t addrlen = sizeof(address);

    // Create socket
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

    while (1) {
        FD_ZERO(&readfds);

        // Add server socket to set
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        // Add client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
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

        // Incoming connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
                perror("accept");
                continue;
            }

            printf("New connection, socket fd is %d, IP: %s, PORT: %d\n",
                   client_fd, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Add new socket to list
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = client_fd;
                    break;
                }
            }
        }

        // Check for IO from clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            sd = client_socket[i];
            if (FD_ISSET(sd, &readfds)) {
                memset(buffer, 0, MAX_INPUT_SIZE);
                valread = read(sd, buffer, MAX_INPUT_SIZE - 1);
                    buffer[valread] = '\0';
		printf("Client(%d): %s", sd, buffer);
                if (valread <= 0) {
                    // Disconnection
                    getpeername(sd, (struct sockaddr*)&address, &addrlen);
                    printf("Client disconnected: %s:%d\n",
                           inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    client_socket[i] = 0;
                } else {
		    fgets(buffer, sizeof(buffer), stdin);
			char sendbuf[MAX_INPUT_SIZE + 50];  // temporary reply buffer
			snprintf(sendbuf, sizeof(sendbuf), "Server echo: %s", buffer);
			write(sd, sendbuf, strlen(sendbuf));

                }
            }
        }        

    }
    return 0;
}

