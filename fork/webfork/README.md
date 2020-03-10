# README.md

En este directorio se encuentran algunos códigos en C que permiten conocer de forma práctica la operación de los Sockets en C.

En particular hay tres archivos que permiten conformar un servidor web muy básico. 

* El programa principal del servidor web está en el archivo [main.c](main.c). 
* Los archivos [dummynet.h](dummynet.h) y [dummynet.c](dummynet.c) contienen las definiciones e implementación de funciones auxiliares que son usadas por el programa definido en [main.c](main.c).
* Finalmente, el [Makefile](Makefile) contiene la definición de un *label* que permite la compilación del servidor web y de la librería sobre la cual este se apoya para crear un servidor web.

