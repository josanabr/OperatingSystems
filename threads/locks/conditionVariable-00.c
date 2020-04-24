/**
Este programa usa las variables de condicion para permitir que un hilo se 
ejecute siempre y se cuando se cumpla cierta condicion. En este caso particular
el hilo que ejecuta el 'main()' se quedara bloqueado mientras la variable 'done'
tenga un valor de '0'. 

AUTHOR: John Sanabria - john.sanabria@correounivalle.edu.co
DATE: 2020-04-24

*/
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_cond_t  c = PTHREAD_COND_INITIALIZER;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int done = 0;

void *child(void *arg) {
    printf("child\n");
    sleep(1);
    pthread_mutex_lock(&m);
    done = 1;
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
    return NULL;
}
int main(int argc, char *argv[]) {
    pthread_t p;
    printf("parent: begin\n");
    pthread_create(&p, NULL, child, NULL);
    pthread_mutex_lock(&m);
    while (done == 0)  
               pthread_cond_wait(&c, &m); // releases lock when going to sleep
    pthread_mutex_unlock(&m);
    printf("parent: end\n");
    return 0;
}
