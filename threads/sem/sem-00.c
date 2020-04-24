/**
Este programa lleva a cabo la siguiente tarea.
1- Permitir que el hilo que ejecuta el 'main()' imprima "parent: begin"
2- Un nuevo hilo se encargara de imprimir "child"
3- Una vez se imprima "child" se puede imprimir "parent: end"

Lo interesante en este contexto es que el hilo del 'main()' se bloquea no
porque el nuevo hilo termine sino porque fue autorizado a traves de la 
funcion 'sem_post'.

El programa entonces debera imprimir:

parent: begin
child
parent: end

AUTHOR: John Sanabria - john.sanabria@correounivalle.edu.co
DATE: 2020-04-24

*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include <semaphore.h>

sem_t s;

void *child(void *arg) {
    sleep(2);
    printf("child\n");
    sem_post(&s); // signal here: child is done
    return NULL;
}

int main(int argc, char *argv[]) {
    sem_init(&s, 0, 0);
    printf("parent: begin\n");
    pthread_t c;
    pthread_create(&c, NULL, child, NULL);
    sem_wait(&s); // wait here for child
    printf("parent: end\n");
    return 0;
}

