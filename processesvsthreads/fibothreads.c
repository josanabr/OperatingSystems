#include <pthread.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "fibo.h"
#include "tiempo.h"

void *worker(void *arg) {
  int *valor = arg;
  struct timeval t0, t1, dt;
  gettimeofday(&t0,NULL);
  fibo(*valor);
  gettimeofday(&t1,NULL);
  timersub(&t1, &t0, &dt);
  printf("Tiempo transcurrido en hilo (%ld) fue %ld.%06ld sec\n",(long)pthread_self(), dt.tv_sec, dt.tv_usec);

  return NULL;
}

int main(int argc, char* argv[]) {
  struct timeval inicial, final, total;
  pthread_t *hilos;
  int totalhilos;
  int i;
  int _fibo = 45;
  gettimeofday(&inicial, NULL);
  if (argc == 2) {
    totalhilos = atoi(argv[1]);
  } else {
    totalhilos = 4;
  }
  hilos = (pthread_t*) malloc(sizeof(pthread_t) * totalhilos);
  assert(hilos != NULL);
  for (i = 0; i < totalhilos; i++) 
    pthread_create(&hilos[i],NULL, worker, &_fibo);
  for (i = 0; i < totalhilos; i++) 
    pthread_join(hilos[i], NULL);
  gettimeofday(&final, NULL);
  timersub(&final, &inicial, &total);
  //printf("\nTiempo TOTAL main %ld.06%ld segundos\n",total.tv_sec,total.tv_usec);

  return 0;
}
