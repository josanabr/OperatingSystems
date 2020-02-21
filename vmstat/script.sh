#!/usr/bin/env bash
#
# Este script ejecuta dos aplicaciones, una computacionalmente intensiva "./exe"
# y otra de copia de datos "cat ./exe > /dev/null". La idea es que el 
# estudiante observe el comportamiento de una herramienta de monitoreo como 
# 'vmstat' e indique como se comportan los campos 'swap', 'io', 'system', 
# 'cpu'; durante la ejecucion de este script.
#
# El usuario puede pasarle uno o dos argumentos al script que deben ser 
# numericos. Si pasa un argumento, este sera usado para indicar cuantas veces 
# se hace la copia de datos. Si pasa un segundo argumento sera usado para 
# determinar cuantas veces se genera y calcula un numero de fibonacci.
#
# Autor: John Sanabria
# Fecha: 2020-02-20
#
MAXEXE=500
TOPE=2000

if [ "${1}" != "" ]; then
   TOPE=${1}
   if [ "${2}" != "" ]; then
     MAXEXE=${2}
   fi
fi
echo "MAXEXE ${MAXEXE} TOPE ${TOPE}"
./exe ${MAXEXE}
I=1
while [ ${I} -lt ${TOPE} ]; do
  cat ./exe > /dev/null
  echo -n "."
  I=$(( I  + 1 ))
done
./exe ${MAXEXE}
