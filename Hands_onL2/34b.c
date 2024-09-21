/*
============================================================================
Name : 34b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to communicate between two machines using socket. (client)            
Date: 21/09/2024
============================================================================
*/


/*
    1. socket() -> create an endpoint for the communication
        sockfetfd = socket(AF_INET, SOCK_STREAM, 0);
    2. connect() -> initiate a connection to a socket
        connectionStatus = connect(socketfd, &socketaddr, sizeof(socketaddr));
    3. Start communicating -> `write` to and `read` from socketfd
*/


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Socket creation failed:");
        exit(1);
    }

    // Define the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Connect to localhost

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection to server failed:");
        close(socket_fd);
        exit(1);
    }
    printf("Connected to the server.\n");

    // Read the welcome message from the server
    int bytes_read = read(socket_fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading from server:");
        close(socket_fd);
        exit(1);
    }
    buffer[bytes_read] = '\0';  // Null-terminate the string
    printf("Server: %s\n", buffer);

    // Send a message to the server
    printf("Enter message to send to server: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    write(socket_fd, buffer, strlen(buffer));

    // Close the socket
    close(socket_fd);
    printf("Connection closed with server.\n");

    return 0;
}




/*
========================================================================================================
OUTPUT:
========================================================================================================
/

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 34b.c -o ./34b
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./34b
Connected to the server.
Server: Hello from the server!
Enter message to send to server: hello
Connection closed with server.
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./34b
Connected to the server.
Server: Hello from the server!
Enter message to send to server: hii
Connection closed with server.
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/  
