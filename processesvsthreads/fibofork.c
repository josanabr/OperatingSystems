#include "fibo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char* argv[]) {
  int i = 0;
  int processes = 4;
  int _fibo = 45;
  struct timeval inicial, final, total;

  gettimeofday(&inicial, NULL);
  if (argc == 2)
    processes = atoi(argv[1]);
  for (i = 0; i < processes; i++) {
    int id = fork();
    if (id == 0) { 
      tiempofibo(_fibo); 
      return 0;
    }
  }
  for (i = 0; i < processes; i++) {
    int pid = wait(NULL);
    printf("Termino proceso %d (%d/%d)\n",pid,i + 1, processes);
  }
  gettimeofday(&final, NULL);
  timersub(&final, &inicial, &total);
  //printf("\nTiempo TOTAL main %ld.06%ld segundos\n",total.tv_sec,total.tv_usec);
  return 0;
}
