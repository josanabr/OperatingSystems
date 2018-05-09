Este directorio contiene ejemplos relativos a como crear librerias en C.

math.c - Muestra un codigo en C que accede a las funciones de la libreria 
         libm.a
         Tomado de este enlace (http://www.cs.dartmouth.edu/~campbell/cs50/buildlib.html)
         Para compilar: gcc -o math -lm math.c

animals.c - Este codigo contiene el main() el cual hace uso de la libreria
            libanimalvoz.a
            Para compilar: make animals

animalvoz.h - Tiene la descripcion de los metodos que se estan disponibles en
              la libreria libanimalvoz.a
animalvoz.c - Tiene la implementacion de los metodos definidos en el archivo de
              cabecera animalvoz.h

Makefile - Tiene las instrucciones que permite compilar lo siguiente:
           - Archivos objeto de animalvoz.c
           - Creacion de la libreria libanimalvoz.a
           - Creacion del binario animals
           - Creacion del binario math

+--------------------+
| HAGALO USTED MISMO |+
+--------------------+|
 +--------------------+

- Asuma que ahora en el archivo animals.c, en las lineas relativas al 
  switch-case, lo que se hace no es solo invocar los metodos definidos en el 
  archivo de cabecera "animalvoz.h" sino que se imprime una cadena de caracteres
  que estos metodos devuelven.  Es decir, reemplace el bloque switch-case del 
  codigo en animals.c con el siguiente codigo:

  //-----------
    switch(option) {
      case 1: printf("Voz del perro \"%s\"\n",guau());
              break;
      case 2: printf("Voz del gato \"%s\"\n",miau());
              break;
      case 3: printf("Voz del pato \"%s\"\n",graznido());
              break;
      default: printf("Opcion no determinada\n");
               break;
    }
  //-----------

  Hint: Para llevar a cabo esta tarea usted debe:
        1- Cambiar la implementacion del archivo animalsvoz.c
        2- Cambiar la implementacion del archivo animalvoz.h

- Construya una libreria en C llamada "libarea.a" la cual tiene los siguientes 
  metodos:
  - double areaRectangulo(int b,int h)
  - double areaTriangulo(int b, int h)

  Su implementacion debe tener:
    - Archivo que contiene el main()
    - Archivo area.h que contiene la definicion de los metodos descritos arriba
    - Archivo area.c que contiene la implementacion de los metodos descritos
      anteriormente
    - Makefile que permite la compilacion de su codigo
