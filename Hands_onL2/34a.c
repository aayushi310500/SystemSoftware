/*
============================================================================
Name : 34a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to communicate between two machines using socket. (Server)            
Date: 21/09/2024
============================================================================
*/



/*
    1. socket() -> create an endpoint for the communication
        sockfetfd = socket(AF_INET, SOCK_STREAM, 0);
    2. bind() -> bind a name to a socket
        bindStatus = bind(socketfd, &socketaddr, sizeof(socketfd));
    3. listen() -> listen for connections on a socket
        listenStatus = listen(socketfd, 2); // backlog -> 2
    4. accept() -> accept a connection on a socket
        connectionfd = accept(socketfd, &socketaddr, sizeof(socketaddr), 0);
    5. Start communicating -> `write` to and `read` from connectionfd
*/




#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     
#include <stdlib.h>

void handle_client(int connection_fd) {
    char buff[100];
    int n;
    

    // ========================= Server - Client communication =================

    // Send a message to the client
    int wb = write(connection_fd, "Hello from the server!", 22);
    if (wb == -1)
        perror("Error writing to client");
    else
        printf("Data sent to client!\n");

    // Read a message from the client
    n = read(connection_fd, buff, sizeof(buff));
    if (n == -1)
        perror("Error reading from client");
    else {
        buff[n] = '\0'; // Null-terminate the string
        printf("Data from client: %s\n", buff);
    }

    // Close the connection after communication
    close(connection_fd);
}


void main()
{
    int socket_fd; 
    int status;      
    int connection_fd;
    socklen_t client_len;
    //struct sockaddr_in address; // Holds the address of the server to communicate
    struct sockaddr_in server_address, client_address;
    char buff[100];

    // Create an endpoint for communicate -> here, create the client side point
    // Create a socket for TCP connection using IPv4
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Server socket successfully created!\n");
    
    
    // Defined server's details
   
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    
     // Bind the socket to a port
    status = bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (status == -1) {
        perror("Error binding socket");
        exit(1);
    }
    printf("Binding to socket was successful!\n");

   
   // Listen for incoming connections (with a backlog of 5)
    status = listen(socket_fd, 5);
    if (status == -1) {
        perror("Error listening on socket");
        exit(1);
    }
    printf("Server is listening on port 8080");
   




 while (1) {
        client_len = sizeof(client_address);

        // Accept a new client connection
        connection_fd = accept(socket_fd, (struct sockaddr *)&client_address, &client_len);
        if (connection_fd == -1) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Client connected!\n");

        // Create a child process using fork to handle the client
        
        if (fork() == 0) {
            // Child process - handles client communication
            close(socket_fd); // Child doesn't need the listening socket
            handle_client(connection_fd);
            exit(1); // Child process exits after handling the client
        } else {
            // Parent process - continues to accept new clients
            close(connection_fd); // Parent doesn't need the client connection socket
        }
    }

}





/*
========================================================================================================
OUTPUT:
========================================================================================================
/

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./34a
Server socket successfully created!
Binding to socket was successful!
Server is listening on port 8080Client connected!
Data sent to client!
Data from client: hello

Client connected!
Data sent to client!
Data from client: hii

^C
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/  
