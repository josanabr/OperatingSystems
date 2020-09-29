#include "fibo.h"
#include "tiempo.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  tiempo inicial, final;
  int _fibo = 10, total;

  if (argc == 2) {
    _fibo = atoi(argv[1]);
  }

  inicial = start();

  total = fibo(_fibo);
  final = stop();

  printf("Para calcular el fibo de %d se tardo %lf segundos. Valor %d\n",_fibo,transcurrido(inicial, final), total);
}
