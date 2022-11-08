#include <unistd.h> // execlp()
#include <stdio.h>  // perror()
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(void) {
  printf("A punto de ejecutar 'ls'\n");
  execlp("ls", "ls", "-l", NULL);
  printf("Despues de ejecutar 'ls'\n");
  perror("Return from execlp() not expected");
  exit(EXIT_FAILURE);
}
