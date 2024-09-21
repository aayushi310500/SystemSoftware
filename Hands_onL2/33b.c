/*
============================================================================
Name : 33b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to communicate between two machines using socket.(server)             
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

void main()
{
    int socket_fd, connection_fd;  
    int clientSize;
    int status;

    struct sockaddr_in address, client;

    char buff[100];

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
        perror("Error:");
        exit(1);
    }
    printf("Now listening for connections on a socket!\n");

    clientSize = (int)sizeof(client);
    connection_fd = accept(socket_fd, (struct sockaddr *)&client, &clientSize);
    if (connection_fd == -1)
        perror("Error :");
    else
    {
 // ========================= Server - Client communication =================

        int wb = write(connection_fd, "I'm the server!", 15);
        if (wb == -1)
            perror("Error :");
        else
            printf("Data sent to client!\n");

        int rb = read(connection_fd, buff, 100);
        if (rb == -1)
            perror("Error :");
        else
            printf("Data from client: %s\n", buff);

// =======================================================================
    }

    close(connection_fd);

    close(socket_fd);
}



/*
========================================================================================================
OUTPUT:
========================================================================================================
/

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./33b
Server side socket successfully created!
Binding to socket was successful!
Now listening for connections on a socket!


aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./33b
Server side socket successfully created!
Binding to socket was successful!
Now listening for connections on a socket!
Data sent to client!
Data from client: I'm the client!
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/  
