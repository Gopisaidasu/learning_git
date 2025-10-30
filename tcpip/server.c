/** server_fork.c **/
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 256
#define PORT 2030

int main() {
    int sockfd, newsfd;
    struct sockaddr_in srv, cln;
    char buffer[MAX_INPUT_SIZE];
    pid_t pid;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    printf("Socket created\n");

    // Setup address
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    srv.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if (bind(sockfd, (struct sockaddr*)&srv, sizeof(srv)) < 0) {
        perror("bind");
        close(sockfd);
        exit(1);
    }
    printf("Binding successful\n");

    // Listen
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close(sockfd);
        exit(1);
    }
    printf("Server is listening on port %d...\n", PORT);

    socklen_t len = sizeof(cln);

    while (1) {
        // Accept new connection
        newsfd = accept(sockfd, (struct sockaddr*)&cln, &len);
        if (newsfd < 0) {
            perror("accept");
            continue;
        }

        printf("\nNew connection accepted (fd=%d), IP: %s, PORT: %d\n",
               newsfd, inet_ntoa(cln.sin_addr), ntohs(cln.sin_port));

        // Fork a child process to handle this client
        pid = fork();

        if (pid < 0) {
            perror("fork");
            close(newsfd);
            continue;
        }

        if (pid == 0) {
            // -------- CHILD PROCESS --------
            close(sockfd); 

            while (1) {
                bzero(buffer, MAX_INPUT_SIZE);

                // Read from client
                int n = read(newsfd, buffer, MAX_INPUT_SIZE - 1);
                if (n <= 0) {
                    printf("Client (fd=%d) disconnected.\n", newsfd);
                    close(newsfd);
                    exit(0);
                }

                buffer[n] = '\0';
                printf("Client (fd=%d): %s", newsfd, buffer);

                // Server types a reply
                printf("Server reply to client (fd=%d): ", newsfd);
                fflush(stdout);
                fgets(buffer, MAX_INPUT_SIZE, stdin);

                // Send reply
                n = write(newsfd, buffer, strlen(buffer));
                if (n < 0) {
                    perror("write");
                    close(newsfd);
                    exit(1);
                }
            }
        } else {
            // -------- PARENT PROCESS --------
            close(newsfd); 
        }
    }

    close(sockfd);
    return 0;
}

