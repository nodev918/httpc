#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 5000
#define PORT 8787

int main(void){

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    
    int connect_result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
    if ( connect_result != 0){
        printf("connect failed\n");
        exit(0);
    }
    else {
        printf("connect success \n");
    }
        
    char buff[MAX] = "hell ooooooo";
    write(sockfd, buff, sizeof(buff));
    bzero(buff,sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    printf("[C] message: %s",buff);    


    return 0;
}