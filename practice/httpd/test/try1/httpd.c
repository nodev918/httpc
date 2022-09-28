#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5002

#define MAX 5000

int main(void){
    
    int sockfd, connfd;
    struct sockaddr_in address, client;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("\nsockfd: %d",sockfd);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    int bind_result = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    printf("\n%d", bind_result);
    if (bind_result == -1)
        printf("\nbind failed");
    else if (bind_result == 0)
        printf("\nbind success");
    else {
      printf("\nbind_result: %d", bind_result);
    }


    if ((listen(sockfd, 5)) != 0) {
      printf("failed");
    } else {
      printf("succ");
    }


    //connfd = listen(sockfd, 5);
    //printf("\n&: %d",connfd);
    //if( connfd == "0" )
    //  printf("\nconnfd: %d",connfd);

        
    while(1){
    }



    return 0;
}
