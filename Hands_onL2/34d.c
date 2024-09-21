/*
============================================================================
Name : 34d.c
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


#include <sys/types.h>  // Import for `socket`, `bind`, `listen`, `accept`
#include <sys/socket.h> // Import for `socket`, `bind`, `listen`, `accept`
#include <netinet/ip.h> // Import for `struct sockaddr_in`, `htons`
#include <stdio.h>      // Import for `perror` & `printf`
#include <unistd.h>     // Import for `_exit`, `read`, `write`
#include <pthread.h>    // Import for `pthread_create`


void communicate(int *fd)
{

    
    char buff[100];
    // ========================= Server - Client communication =================

    int wb = write(*fd, "I'm the server!", 15);
    if (wb == -1)
        perror("Error :");
    else
        printf("Data sent to client!\n");

    int rb = read(*fd, buff, 100);
    if (rb == -1)
        perror("Error:");
    else
        printf("Data from client: %s\n", buff);

    // =======================================================================

    close(*fd);
}

void main()
{
    int socket_fd, connection_fd;
    int status;
    int clientSize;

    struct sockaddr_in address, client;

    pthread_t threadID;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Server side socket successfully created!\n");

    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    status = bind(socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Binding to socket was successful!\n");

    status = listen(socket_fd, 2);
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Now listening for connections on a socket!\n");

    while (1)
    {
        clientSize = (int)sizeof(client);
        connection_fd = accept(socketFileDescriptor, (struct sockaddr *)&client, &clientSize);
        if (connection_fd == -1)
            perror("Error :");
        else
        {   
            if (pthread_create(&threadID, NULL, (void *)communicate, &connection_fd))
                perror("Error:");
        }
    }

    close(socket_fd);
}
