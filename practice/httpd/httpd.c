#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#define MAX 100
#define PORT 8888

const char *readFile(const char *fileName){
  FILE *fptr;
  char ch;
  char buff[MAX];
  char *p;
  int n = 0;

  p = buff;

  fptr = fopen(fileName,"r");
  if(fptr == NULL)
  {
    printf("Error!");
    exit(1);
  }

  while((ch = fgetc(fptr)) != EOF)
  {
    p[n++] = ch;
  }
  
  p[n] = '\0';

  fclose(fptr);

  return p;

}


int listeny(int port){
  int sockfd;
  int bind_result;
  int listen_result;
  struct sockaddr_in address;
 

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( sockfd == -1 ){
    printf("[H] socket create failed\n");
    exit(0);
  } else { 
    printf("[H] sockfd: %d\n",sockfd);
  }

  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(INADDR_ANY);
  bind_result = bind(sockfd,(struct sockaddr *)&address, sizeof(address));
  if ( bind_result == -1 ){
    printf("[H] socket bind failed\n");
    exit(0);
  } else {
    printf("[H] bind port: %d\n", port);
  }
  
  listen_result = listen(sockfd, 5);
  if ( listen_result == -1 ){
    printf("[H] socket listen failed\n");
  } else {
    printf("[H] socket listening port: %d\n", port);
  }

  return sockfd; 
}

int main(){
  int sockfd; 
  struct sockaddr_in client;

  char buff[MAX];
  int n;
  char message[MAX] = "hello from server";


  printf("\n");

  sockfd = listeny(PORT);
  
  while(1){
    int connfd;    

    unsigned int len = sizeof(client);
    connfd = accept(sockfd, (struct sockaddr *)&client, &len);
    if ( connfd != -1 ){
      printf("[H] client connected \n");
      printf("[H] connfd: %d\n",connfd);
      read(connfd, buff, sizeof(buff));
      printf( "[H] client: %s\n", buff );
      //write(connfd, message, sizeof(message));

      //const char *p;
      //p = readFile("./index.html");
      //printf("%s",p);
      //write(sockfd, p, sizeof(p));
      int numchars = 1;
      char buf[1024];

      buf[0] = 'A'; buf[1] = '\0';
      while ((numchars >0) && strcmp("\n", buf)){
        numchars = get_line(connfd, buf, sizeof(buf));
      }



     }
    if (connfd == -1 ){
      printf("[H] connfd is -1 . . .\n");
      exit(1);
    }

  }

  close(sockfd);
  return 0;
}


