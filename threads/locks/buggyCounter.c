/**

Este programa en C y que usa hilos, evidencia un problema de concurrencia
al permitir que dos hilos modifiquen una variable compartida llamada 'counter'.
Este programa espera recibir como argumento un numero que indica que tantas
veces debe sumar '1' a la variable 'counter' cada hilo. Dependiendo de la
velocidad de su computador ese valor que pase por argumento debera ser alto.

El lector de este codigo puede usar algun mecanimos de control de acceso a 
recursos compartidos para garantizar que al final el programa sume de forma
correcta el valor que aporta cada hilo.

AUTHOR: John Sanabria - john.sanabria@correounivalle.edu.co
DATE: 2020-04-24
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "common.h"
#include "common_threads.h"

int max;
volatile int counter = 0; // shared global variable

void *mythread(void *arg) {
    char *letter = arg;
    int i; // stack (private per thread) 
    printf("%s: begin [addr of i: %p]\n", letter, &i);
    for (i = 0; i < max; i++) {
	counter = counter + 1; // shared: only one
    }
    printf("%s: done\n", letter);
    return NULL;
}
                                                                             
int main(int argc, char *argv[]) {                    
    if (argc != 2) {
	fprintf(stderr, "usage: main-first <loopcount>\n");
	exit(1);
    }
    max = atoi(argv[1]);

    pthread_t p1, p2;
    printf("main: begin [counter = %d] [%x]\n", counter, 
	   (unsigned int) &counter);
    Pthread_create(&p1, NULL, mythread, "A"); 
    Pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    Pthread_join(p1, NULL); 
    Pthread_join(p2, NULL); 
    printf("main: done\n [counter: %d]\n [should: %d]\n", 
	   counter, max*2);
    return 0;
}


