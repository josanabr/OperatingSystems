# Probando vmstat

El `vmstat` es un comando que permite observar el comportamiento del sistema operativo en un momento determinado. 
El `vmstat` es capaz de proporcionar información relativa al uso de la CPU, las interrupciones manejadas por el sistema operativo, cantidad de bloques de disco leidos o guardados, entre otras métricas. 
Para mayor información visite este [enlace](https://www.linode.com/docs/uptime/monitoring/use-vmstat-to-monitor-system-performance/).

## Hágalo usted mismo

Para este taller usted deberá descargar los archivos que se encuentran en este directorio:

* [exe.c](exe.c)
* [script.sh](script.sh)

A continuación ejecutar los siguientes pasos,

* Compilar el archivo `.c` y generar un ejecutable llamado `exe`.
* Abrir una terminal en la cual ejecutará el programa `vmstat` de modo que **cada segundo** este mostrando el estado del sistema operativo en cuanto a uso de CPU, manejo de interrupciones, cantidad de bloques de disco que se leen o se escriben, entre otros. Para entender la información que presenta `vmstat` por favor dirigirse al [enlace](https://www.linode.com/docs/uptime/monitoring/use-vmstat-to-monitor-system-performance/) que se indicó arriba. Antes de continuar, observe con cuidado los valores mostrados por `vmstat`.
* En la terminal donde compiló el archivo `.c`, ejecutar el script, `./script.sh`.
* Observar la información suministrada por el `vmstat` e indicar:

  * Cuando el script presenta el mensaje `En ./exe MAXIter ...` que recursos muestran un cambio en su estado o sus valores numéricos según `vmstat`.
  * Cuando el script está mostrando una serie de `.` por pantalla que recursos muestran un cambio en su estado o sus valores numéricos según `vmstat`.
  * ¿Qué se puede concluir de lo observado?
