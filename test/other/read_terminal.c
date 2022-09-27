#include <stdio.h>
#include <stdlib.h>

#define MAX 300


int main(void){
  char ch ;
  char buff[MAX];
  char *p;

  p = buff;

  while( (ch = getchar()) != '\n' && ch != EOF){
    *p++ = ch;    
  }

  printf("%s",buff);

  
  
  return 0;
}
