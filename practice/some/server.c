#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <sys/socket.h> // socket()
#include <netinet/in.h> // struct sockaddr_in
#include <strings.h>    // bzero()
#include <unistd.h>     // read(), write()
#define PORT 5566
#define MAX 80


int main(){
  

  // socket()
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd) {
    printf("sockfd: %d\n", sockfd);
  } else {
    printf("sockfd create failed");
    exit(0);
  }


  // bind()
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  address.sin_port = htons(PORT);  

  int bind_result = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
  if ( bind_result !=0 ) {
    printf("socket bind failed ...\n");
    exit(0);
  } else{
    printf("socket bind success !\n");
  }

  // listen()
  int listen_result = listen(sockfd, 5);
  if ( listen_result != 0){
    printf("listen failed...\n");
    exit(0);
  } else {
    printf("listening port: %d\n", PORT);
  }

  // accept()
  struct sockaddr_in client;
  int length = sizeof(client);
  int connfd = accept(sockfd, (struct sockaddr *)&client, &length);
  

  /* handle a accepted user client */
  char buff[MAX];
  int n;
  char reply[MAX] = "reply from server";
  for (;;){
    bzero(buff, MAX); // init memory
    
    // read from client
    read(connfd, buff, sizeof(buff));
    printf("from client: %s, send: %s\n", buff, reply);

    // get user input
//    bzero(buff, MAX);
//    n = 0;
//    while ((buff[n++] = getchar()) != '\n');

    // write to client
    write(connfd, buff, sizeof(buff));

//    if (strncmp("exit", buff, 4) ==0 ){
//      printf("server exit...\n");
//      break;
//    }
//
    break;
  }
  

  close(sockfd);
  

  return 0;
}
