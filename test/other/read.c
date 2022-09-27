#include <stdio.h>
#include <stdlib.h>

enum { SIZE = 20 };

int main(void){
  char buf[SIZE];
  char *p;
  int ch;

  p=buf;
  printf("please, input a single char: ");
  
  while((ch = getchar()) != '\n' && ch != EOF){
    *p++ = (char)ch;
  }
  *p++ = 0;
  
  if (ch == EOF){
    printf("EOF encountered\n");
  }

  printf("%s\n", buf);
  
  exit(EXIT_SUCCESS);
}
