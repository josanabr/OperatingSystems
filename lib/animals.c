#include <stdio.h>
#include <string.h>
#include "animalvoz.h"

int main(int argc, char** argv) {

  while (1) {
    int option;
    printf("\n-- Menu - voz de animal --\n");
    printf("\n");
    printf("[1] Perro\n");
    printf("[2] Gato\n\
[3] Pato\n");
    printf("Digite su opcion: ");
    scanf("%d",&option);
    switch(option) {
      case 1: guau();
              break;
      case 2: miau();
              break;
      case 3: graznido();
              break;
      default: printf("Opcion no determinada\n");
               break;
    }
    if (option < 1 || option > 3) break;
  }
  return 0;
}
