#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h> 
#include <stdlib.h>
#include<time.h>
#include "shell.h"
#define BUFFSIZE 128

void socp(char *fonte, char *destino){
  int fdIn = open(fonte, O_RDONLY);
  if(fdIn == -1){ 
    printf("Error Number % d\n", errno);  
    perror("open failed");                 
  }

  int fdOut = creat(destino, S_IRUSR| S_IWUSR );
  if(fdOut == -1){
    printf("Error Number % d\n", errno);  
    perror("creat failed");  
  }

  ioCopy(fdIn, fdOut);
}

void ioCopy (int IN, int OUT) //no error reporting
{ 
 int n;
 char buf[BUFFSIZE];
 while ( ( n = read (IN, buf, BUFFSIZE)) > 0)
 { 
  if (write (OUT, buf, n) != n)
    perror("Erro de escrita!\n");
 }
 if (n < 0)
  perror("Erro de leitura!\n");
}
