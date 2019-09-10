/*
Esta es la parte del codigo que tiene el corazon del servidor.

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

#include "dummynet.h"


//
// Este metodo tiene las instrucciones de codigo para inicializar un servidor.
// Recibe una cadena de caracteres que representa el identificador de puerto
// por donde escuchara el servidor.
//
int startServer(char *port)
{
  struct addrinfo hints, *res, *p;
  int listenfd;

  // getaddrinfo for host
  memset (&hints, 0, sizeof(hints));
  // Se indica que son sockets de tipo TCP
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  // Esta asignacion 'ai_flags' y el 'NULL' en 'getaddrinfo()'
  // permiten que la variable "res" pueda ser usada  con 
  // 'bind()' y 'accept()'
  hints.ai_flags = AI_PASSIVE;
  if (getaddrinfo( NULL, port, &hints, &res) != 0)
  {
    perror ("getaddrinfo() error");
    exit(1);
  }
  // socket and bind
  // se asocia el servidor a las interfaces de red que 
  // tiene disponibles el equipo donde corre la aplicacion
  for (p = res; p!=NULL; p=p->ai_next)
  {
    listenfd = socket (p->ai_family, p->ai_socktype, 0);
    if (listenfd == -1) continue;
    if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) break;
  }
  if (p==NULL)
  {
    perror ("socket() or bind()");
    exit(1);
  }

  // se limpia la variable
  freeaddrinfo(res);

  // listen for incoming connections
  if ( listen (listenfd, 1000000) != 0 )
  {
    perror("listen() error");
    exit(1);
  }
  return listenfd;
}

//
// Este metodo se encarga de hablar con el usuario y de responder a la solicitud
// que este requiera.
//
void respond(int client)
{
  char mesg[99999], *reqline[3], data_to_send[BYTES], path[99999];
  int rcvd, fd, bytes_read;

  memset( (void*)mesg, (int)'\0', 99999 );

  rcvd=recv(client, mesg, 99999, 0);

  if (rcvd<0)    // receive error
    fprintf(stderr,("recv() error\n"));
  else if (rcvd==0)    // receive socket closed
    fprintf(stderr,"Client disconnected upexpectedly.\n");
  else    // message received
  {
    printf("%s", mesg);
    reqline[0] = strtok (mesg, " \t\n");
    printf("\n\n(%s)\n\n",reqline[0]);
    if ( strncmp(reqline[0], "GET\0", 4)==0 )
    {
      reqline[1] = strtok (NULL, " \t");
      reqline[2] = strtok (NULL, " \t\n");

      printf("\n\n(%s) (%s) (%s)\n\n",reqline[0],reqline[1],reqline[2]);
      if ( strncmp( reqline[2], "HTTP/1.0", 8)!=0 && strncmp( reqline[2], "HTTP/1.1", 8)!=0 )
      {
        write(client, "HTTP/1.0 400 Bad Request\n", 25);
      }
      else
      {
        if ( strncmp(reqline[1], "/\0", 2)==0 )
          reqline[1] = "/index.html";        //Because if no file is specified, index.html will be opened by default (like it happens in APACHE...

        strcpy(path, ROOT);
        strcpy(&path[strlen(ROOT)], reqline[1]);
        printf("file: %s\n", path);

        if ( (fd=open(path, O_RDONLY))!=-1 )    //FILE FOUND
        {
          send(client, "HTTP/1.0 200 OK\n\n", 17, 0);
          while ( (bytes_read=read(fd, data_to_send, BYTES))>0 )
            write (client, data_to_send, bytes_read);
        }
        else    write(client, "HTTP/1.0 404 Not Found\n", 23); //FILE NOT FOUND
      }
    }
  }

  //Closing SOCKET
  shutdown (client, SHUT_RDWR);         //All further send and recieve operations are DISABLED...
  close(client);
}

int listenfd(int portfd) {
  int client;
  struct sockaddr_in clientaddr;
  socklen_t addrlen;

  addrlen = sizeof(clientaddr);
  client = accept (portfd, (struct sockaddr *) &clientaddr, &addrlen);
   
  return client;
}
