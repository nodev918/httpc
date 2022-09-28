#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8888
#define MAX 100

// void func(int sockfd)
// {
//     char buff[MAX];
//     int n;
//     for (;;) {
//         bzero(buff, sizeof(buff));
//         printf("Enter the string : ");
//         n = 0;
//         while ((buff[n++] = getchar()) != '\n')
//             ;
//         write(sockfd, buff, sizeof(buff));
//         bzero(buff, sizeof(buff));
//         read(sockfd, buff, sizeof(buff));
//         printf("From Server : %s", buff);
//         if ((strncmp(buff, "exit", 4)) == 0) {
//             printf("Client Exit...\n");
//             break;
//         }
//     }
// }

void send_message(int sockfd, char *message){
  write(sockfd, message, sizeof(message));  
  printf("hihi\n");
}

int main(void){
  int sockfd;
  struct sockaddr_in address;


  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr("127.0.0.1");
  address.sin_port = htons(PORT);



  if( connect(sockfd, (struct sockaddr*)&address, sizeof(address)) != 0){
    printf("connect failed \n");
    exit(0);
  } else {
    printf("connect server success \n");
  }

  char message[MAX] = "hello";
  send_message(sockfd, message);
  // func(sockfd);

  return 0;
}
