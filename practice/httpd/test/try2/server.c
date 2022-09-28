#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>

#define MAX 5000
#define PORT 8787

int main(void){
    int sockfd, connfd;
    struct sockaddr_in address, client;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        printf("socket() failed\n");
        exit(0);
    }
    else
        printf("socket fd createdddddd \n");
    
    bzero(&address, sizeof(address));
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);
    address.sin_family = AF_INET;

    if ((bind(sockfd, (struct sockaddr *)&address,sizeof(address))) != 0 ){
        printf("bind failed\n");
        exit(0);
    }
    else 
        printf("bind success\n");
    
    if ((listen(sockfd, 5)) != 0) {
        printf("listen failed \n");
        exit(0);
    }
    else
        printf("listening %d\n", PORT);

    char buff[MAX];
    while(1){
        unsigned int len = sizeof(client);
        connfd = accept(sockfd, (struct sockaddr *)&client, &len);
        if (connfd < 0){
            printf("accept failed \n");
            exit(0);
        }
        else{
            printf("connfd: %d\n",connfd);
            bzero(buff,sizeof(buff));
            read(connfd, buff, sizeof(buff));
            printf("[H] message: %s\n", buff);
            
            write(connfd, buff, sizeof(buff));
        }
            
            
    }


    return 0;
}