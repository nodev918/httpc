#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX 5000
#define PORT 5567

int main(){

  int sockfd;
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  if( !sockfd ){
    printf("[F] sicket() failed\n");
  } else{ 
    printf("[P] sockfd: %d\n", sockfd);
  }
  
  struct sockaddr_in address, client;
  address.sin_family= AF_INET;
  address.sin_port = PORT;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  int bind_result = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
  if(bind_result !=0){
    printf("[F] bind() failed\n");
    exit(0);
  } else {
    printf("[P] bind() success\n");
  }

  int listen_result = listen(sockfd, 5);
  if ( listen_result != 0 ){
    printf("[F] listen failed...\n");
  } else {
    printf("[P] listening port: %d\n\n\n\n",PORT);
  }

  

  return 0;
}
