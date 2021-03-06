# Cache

La cache es uno de los componentes determinantes en la velocidad de procesamiento en un sistema de cómputo.
El código que se encuentra en `demo.c` ilustra como el acceder a diferentes regiones de memoria afecta dramáticamente en el rendimiento de un programa.

Para ejecutar el código en este directorio debe ejecutar el siguiente comando.

```
make
```

Resultado de esta ejecución se crea un archivo llamado `demo`.
Para ejecutar dicho archivo se debe correr el siguiente comando.

```
./demo
```

Una salida plausible de ejecución es la siguiente

```
Loop 1
	CPU time 1.398617 secs.
	CPU time 0.610951 secs.
	CPU time 0.270884 secs.

Loop 2
	CPU time for (j = 1) 0.239597 secs.
	CPU time for (j = 2) 0.262464 secs.
	CPU time for (j = 4) 0.243156 secs.
	CPU time for (j = 8) 0.250589 secs.
	CPU time for (j = 16) 0.248944 secs.
	CPU time for (j = 32) 0.172894 secs.
	CPU time for (j = 64) 0.103724 secs.
	CPU time for (j = 128) 0.058136 secs.
	CPU time for (j = 256) 0.034080 secs.
	CPU time for (j = 512) 0.025643 secs.
	CPU time for (j = 1024) 0.012108 secs.

Loop 3
	CPU time for (j = 1) 0.355355 secs.
	CPU time for (j = 2) 0.179497 secs.
	CPU time for (j = 4) 0.088257 secs.
	CPU time for (j = 8) 0.044870 secs.
	CPU time for (j = 16) 0.022341 secs.
	CPU time for (j = 32) 0.011157 secs.
	CPU time for (j = 64) 0.005497 secs.
	CPU time for (j = 128) 0.002813 secs.
	CPU time for (j = 256) 0.002327 secs.
	CPU time for (j = 512) 0.000857 secs.
	CPU time for (j = 1024) 0.000462 secs.
```

## Actividad

Resolver a continuación los siguientes puntos en clase

* ¿Qué son las banderas o *flags* de un programa de la línea de comandos? Explique qué significan las banderas usadas a la hora de compilar el programa `demo.c`, `gcc -Wall -O3  demo.c -o demo`

* La constante `MAX_SIZE` que valor representa. La variable `*arr` qué cantidad de memoria ocupa?

* Haga las modificaciones necesarias en el código para sacar los promedios de ejecución de cada uno de los tres loops.

* La instrucción `j <<= 1` qué representa? Explique en palabras que quiere decir esta sentencia del ciclo for `for (j = 1 ; j <= 1024 ; j <<= 1)`. ¿Cuántas iteraciones llevará a cabo este ciclo?

* El número de veces que se ejecutan los ciclos 2 y 3, es la misma? ¿Por qué se presentan cambios en los tiempos de ejecución?

