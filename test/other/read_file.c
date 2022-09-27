#include<stdio.h>
#include<stdlib.h>
#define MAX 5000


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

int main(void){

  const char *p;

  p = readFile("./index.html");

  printf("%s",p);

  return 0;

}
