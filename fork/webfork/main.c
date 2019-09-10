/*
AUTHOR: Abhijeet Rastogi (http://www.google.com/profiles/abhijeet.1989)

This is a very simple HTTP server. Default port is 10000 and ROOT for the server is your current working directory..

You can provide command line arguments like:- $./a.aout -p [port] -r [path]

for ex. 
$./a.out -p 50000 -r /home/
to start a server at port 50000 with root directory as "/home"

$./a.out -r /home/shadyabhi
starts the server at port 10000 with ROOT as /home/shadyabhi

Modificado para efectos de la clase 2019-03-07 
Por John Sanabria - john.sanabria@correounivalle.edu.co

 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<signal.h>
#include<fcntl.h>

#define BYTES 1024

void error(char *);
void startServer(char *);
void respond();

int main(int argc, char* argv[])
{
  struct sockaddr_in clientaddr;
  socklen_t addrlen;
  int listenfd, client;
  char c;
  char *ROOT;
  char PORT[6];

  if (argc == 2) {
    strcpy(PORT, argv[1]);
  } else {
    strcpy(PORT,"10000");
  }
  //Default Values PATH = ~/ and PORT=10000
  ROOT = getenv("PWD");

  int slot=0;
  printf("Server started at port no. %s%s%s with root directory as %s%s%s\n","\033[92m",PORT,"\033[0m","\033[92m",ROOT,"\033[0m");
  // Setting all elements to -1: signifies there is no client connected
  startServer(PORT);

  // ACCEPT connections
  while (1)
  {
    addrlen = sizeof(clientaddr);
    client = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);

    if (client<0) // error en la solicitud
      error ("accept() error");
    else // efectivamente se atiende la solicitud
    {
      // incluir el codigo de modo que el hijo
      // del servidor web atienda la peticion
      respond();
    }
  }

  return 0;
}

