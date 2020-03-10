/*

Este programa en C debe recibir el credito inicialmente de la siguiente persona:
AUTHOR: Abhijeet Rastogi (http://www.google.com/profiles/abhijeet.1989)
https://blog.abhi.host/blog/2010/04/15/very-simple-http-server-writen-in-c/

Convertirlo en su version modular y eliminar argumentos de invocacion del 
comando son obras de John Sanabria

Modificado para efectos de la clase 2019-09-10 
Por John Sanabria - john.sanabria@correounivalle.edu.co

 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "dummynet.h"

int main(int argc, char* argv[])
{
  int client;
  int portfd;
  char PORT[6];

  // Se asigna un numero de puerto al servidor 
  if (argc == 2) {
    strcpy(PORT, argv[1]);
  } else {
    strcpy(PORT,"10000");
  }

  printf("Server to be started at port no. [%s] with root directory as [%s]\n",PORT,ROOT);
  portfd = startServer(PORT);

  // ACCEPT connections
  while (1)
  {
    // La funcion listenfd escucha por una peticion que realice un client,
    // ejemplo un navegador
    client = listenfd(portfd);
    if (client<0) // error en la solicitud
      perror("accept() error");
    else // efectivamente se atiende la solicitud
    {
      // incluir el codigo de modo que el hijo
      // del servidor web atienda la peticion
      respondHTTP(client);
    }
  }

  return 0;
}

