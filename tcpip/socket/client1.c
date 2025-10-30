#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 2030
#define MAX_INPUT_SIZE 256

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[MAX_INPUT_SIZE];
    fd_set readfds;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    printf("Connected to server. Type messages below.\n");

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        FD_SET(sock, &readfds);

        int max_fd = sock;
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("select");
            break;
        }

        // From keyboard
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            send(sock, buffer, strlen(buffer), 0);
        }

        // From server
        if (FD_ISSET(sock, &readfds)) {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(sock, buffer, sizeof(buffer) - 1);
            if (valread <= 0) {
                printf("Server disconnected.\n");
                break;
            }
            printf("Server: %s\n", buffer);
        }
    }

    close(sock);
    return 0;
}

