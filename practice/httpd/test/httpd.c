#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <strings.h>
#define MAX 5000
#define PORT 5001



int main(void){
    int sockfd, connfd;
    struct sockaddr_in address, client;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if( (bind(sockfd, (struct sockaddr *)&address, sizeof(address))!= -1)){
        printf("\nport binding: %d", PORT);
    } else {
        printf("\nport binding failed");
        exit(1);
    }
    
    // if ((listen(sockfd, 5)) != 0) {
    //     printf("Listen failed...\n");
    //     exit(0);
    // }
    // else
    //     printf("Server listening..\n");

    // int listen_result = (listen(sockfd, 5))
    // printf("\n ** %d",listen_result);

    // if(listen_result == 0){
    //     printf("hihi");
    //     // printf("\nlistening port: %d",PORT);
    // } 
    
    while(1){
        unsigned int len = sizeof(client);
        connfd = accept(connfd, (struct sockaddr *)&client, &len);

        if (connfd != -1){
            char buff[MAX];
            printf("\nconnect: %d", connfd);
            
            bzero(buff,sizeof(buff));
            read(connfd,buff,sizeof(buff));
            printf("[H] message: %s",buff);

            char message[MAX] = "hello";
            write(connfd, message, sizeof(message));
        }
    }
    
    close(sockfd);

    return 0;
}