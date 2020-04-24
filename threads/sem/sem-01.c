

/**

Este programa usa semaforos y permite el compartirlos entre procesos.
El ejemplo 'sem-00.c' permitia compartir el semaforo entre hilos.

Descripcion de lo que hace este programa.
En una clase anterior habiamos visto que un padre puede esperar a que
termine un hijo a traves de la funcion wait. Sin embargo, no era natural
que un hijo esperara a que su papa terminara para luego continuar el.
De hecho, En que escenarios ese comportamiento resultaria util?
Pues bien, usando 'semaphores' es posible lograr este comportamiento.

Comienza papa
Termina papa
Comienza hijo
Termina hijo

Basado en: http://www.vishalchovatiya.com/semaphore-between-processes-example-in-c/

ipcs -s: permite ver que semaforos estan definidos en un programa en C
Fuente: https://www.thegeekstuff.com/2010/08/ipcs-command-examples/

AUTHOR: John Sanabria - john.sanabria@correounivalle.edu.co
DATE: 2020-04-24

*/
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define Sem_init(v) sem_open(semName, O_CREAT, 0600, v)
#define Sem_close(v) sem_close(v)
#define Sem_post(v) sem_post(v)
#define Sem_unlink(v) sem_unlink(v)
#define Sem_wait(v) sem_wait(v)

char *semName = "asdfsd";

void papa() {
  sem_t *sem_id = Sem_init(0);

  if (sem_id == SEM_FAILED) {
    perror("Padre fallo al crear el semaforo\n");
    return;
  }
  printf("Comienza papa\n");
  sleep(2);
  printf("Termina papa\n");
  Sem_post(sem_id);
}

void hijo() {
  sem_t *sem_id = Sem_init(0);

  if (sem_id == SEM_FAILED) {
    perror("Hijo fallo al crear el semaforo\n");
    return;
  }
  Sem_wait(sem_id);

  printf("Comienza el hijo\n");
  printf("Termina el hijo\n");
  Sem_close(sem_id);
  Sem_unlink(semName);
}

int main(int argc, char* argv[]) {
  pid_t pid;

  pid = fork();

  if (pid < 0) {
    perror("No se pudo crear un nuevo proceso\n");
    exit(1);
  }
  if (pid == 0) {
    hijo();
  } else {
    papa();
  }
}

