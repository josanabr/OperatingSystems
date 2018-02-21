# README.md

El programa `fibo.c` se usa para mostrar la relevancia de programar en paralelo.
Para evidenciar el poder del paralelismo es necesario probar este código en un equipo que tenga o varios procesadores o varios núcleos.

## Compilación

Para llevar a cabo la compilacion de una version secuencial de este programa·se ejecuta compila la siguiente manera
```
gcc -o fibos fibo.c
```

Para llevar a cabo la compilacion de la version paralela de este programa se compila de la siguiente manera
```
gcc -fopenmp -o fibop fibo.c
```

## Medición de tiempos de ejecución

Para llevar a cabo la medicion de tiempos se sugiere ejecutar el siguiente par de comandos, version secuencial
```
      time ./fibos
```

Version paralela,
```
      time ./fibop
```

## Actividad 

* En lugar de usar la función de `fibo` utilice la [función de Ackerman](https://en.wikipedia.org/wiki/Ackermann_function)

* ¿Qué caracteriza o hace especial a la función recursiva de Ackerman? Explique en términos *castizos* 
