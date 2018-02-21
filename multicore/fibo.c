/**
 * Programa que se usa para mostrar la relevancia de programar en paralelo.
 *
 * Para llevar a cabo la compilacion de una version secuencial de este programa 
 * se ejecuta de la siguiente manera
 *      gcc -o fibos fibo.c
 *
 * Para llevar a cabo la compilacion de la version paralela de este programa se
 * ejecuta de la siguiente manera
 *      gcc -fopenmp -o fibop fibo.c
 *
 * Para llevar a cabo la medicion de tiempos se sugiere ejecutar el siguiente 
 * par de comandos
 *      time ./fibos
 *      time ./fibop
 *
 * Author: John Sanabria - john.sanabria@correounivalle.edu.co
 * Date: 2018-02-21
 */
#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

#define MAXARRAY 10000
#define TOPE 33

// Devuelve el elemento en la serie de Fibonacci que ocupa la posicion 'n'.
int fibo(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fibo(n - 1) + fibo(n - 2);
}

int main(int argc, char** argv) {
  int orig[MAXARRAY], dest[MAXARRAY];
  int i;

  srand(time(NULL)); // inicializacion del generador de numeros aleatorios
  printf("Inicializando arreglo orig");
  for (i = 0; i < MAXARRAY; i++)
    orig[i] = rand() % TOPE;
  printf("...hecho\n");

  printf("Calculando fibonacci");
#pragma omp parallel for
  for (i = 0; i < MAXARRAY; i++) // calculo de fibo para cada elemento de orig
    dest[i] = fibo(orig[i]);
  printf("...hecho\n");

  for (i = 0; i < MAXARRAY; i++) // impresion de resultados
    printf("[%d] fibo(%d) = %d\n",i+1,orig[i],dest[i]);

  return 0;
}
