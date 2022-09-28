#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>    // bzero()
#include <string.h>     // strncmp()
#define MAX 5000


int main(){
  
  int sockfd;
  struct sockaddr_in address;
  int result;
  


  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(5566);

  result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

  if (result == -1)
  {
    perror("client error");
    exit(1);
  } 

  
  char buff[MAX];
  int n;
  for(;;){

    n=0;
    bzero(buff, sizeof(buff));
    while((buff[n++] = getchar()) != '\n');
    write(sockfd, buff, sizeof(buff));
  
    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    printf("from server: %s", buff);
    if ( (strncmp(buff, "exit", 4)) == 0 ){
      printf("client exit...\n");
    }

  }
  
  close(sockfd);

   return 0;
}
