#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>

#define PORT 5001
#define MAX 5000

int main(void){
    
    int connfd;
    struct sockaddr_in address;
    
    connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("connfd: %d",connfd);

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if ((connect(connfd, (struct sockaddr *)&address, sizeof(address))) == -1){
        printf("\nconnect failed ...");
    }
    
    char message[MAX] = "hello";
    write(connfd, message, sizeof(message));

    char buff[MAX];
    bzero(buff,sizeof(buff));
    read(connfd,buff,sizeof(buff));
    printf("[C] message: %s",buff);





    return 0;
}