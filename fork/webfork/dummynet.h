#ifndef __DUMMYNET__
#define __DUMMYNET__

#define BYTES 1024
#define ROOT getenv("PWD") 

int startServer(char *);
void respond(int);
int listenfd(int);

#endif
