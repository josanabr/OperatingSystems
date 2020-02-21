#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXITER 1000
#define MAXFIBO 40
#define FILENAME "fiboseries.txt"
#define FILEOUTPUT "salida.txt"

int fibonacci(int f) {
  if (f == 1) return 0;
  if (f == 2) return 1;
  return fibonacci(f - 1) + fibonacci(f - 2);
}

int main(int argc, char** argv) {
  FILE *fd, *fdo;
  int i;
  int MAXIter = MAXITER;

  if (argc == 2) {
    MAXIter = atoi(argv[1]);
  }
  printf("En %s MAXIter %d\n", argv[0], MAXIter);
  fd = fopen(FILENAME, "w");
  fdo = fopen(FILEOUTPUT, "w");
  if (!fd || !fdo) {
   printf("Error al abrir el archivo\n");
   exit(-1);
  }
  srand(time(NULL));
  for (i = 0; i < MAXIter; i++) {
    int val = (rand()%MAXFIBO) + 1;
    fprintf(fd,"%d\n",val);
  }
  fclose(fd);

  fd = fopen(FILENAME, "r");
  if (!fd) {
   printf("Error al abrir el archivo\n");
   exit(-1);
  }
  for (i = 0; i < MAXIter; i++) { 
    int val;
    fscanf(fd,"%d\n",&val);
    fprintf(fdo, "%d\n", fibonacci(val));
  }
  fclose(fd); fclose(fdo);

  exit(0);
}
