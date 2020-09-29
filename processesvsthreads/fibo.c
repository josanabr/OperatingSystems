#include "tiempo.h"
#include <unistd.h>
#include <stdio.h>
int fibo(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return fibo(n - 1) + fibo(n - 2);
}

int tiempofibo(int f) {
  tiempo inicial, final;
  int _f;
  inicial = start();
  _f = fibo(f);
  final = stop();
  printf("[%d] Calculando el fibo de %d tomo %lf segundos. Valor %d\n",getpid(),f,transcurrido(inicial,final), _f);
  return _f;
}
