/*
============================================================================
Name : 34c.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to communicate between two machines using socket. (Client)            
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
#include <unistd.h>    
#include <stdlib.h>

void main()
{
    int socket_fd; 
    int status;       

    struct sockaddr_in address; // Holds the address of the server to communicate

    char buff[100];

    // Create an endpoint for communicate -> here, create the client side point
    // Create a socket for TCP connection using IPv4
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Client side socket successfully created!\n");

    // Defined server's details
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    status = connect(socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Client to server connection successfully established!\n");

    // ========================= Client - Server communication =================

    int rb = read(socket_fd, buff, 100);
    
    if (rb == -1)
        perror("Error :");
    else
        printf("Data from server: %s\n", buff);

    int wb = write(socket_fd, "I'm the client!", 15);
    if (wb == -1)
        perror("Error:");
    else
        printf("Data sent to server! press enter and exit");

    getchar();
    
    // =======================================================================

    close(socket_fd);
}



/*
========================================================================================================
OUTPUT:
========================================================================================================
/

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 34c.c -o ./34c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./34c
Client side socket successfully created!
Client to server connection successfully established!
Data from server: I'm the server!
Data sent to server!nhj
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./34c
Client side socket successfully created!
Client to server connection successfully established!
Data from server: I'm the server!
Data sent to server!
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/  
