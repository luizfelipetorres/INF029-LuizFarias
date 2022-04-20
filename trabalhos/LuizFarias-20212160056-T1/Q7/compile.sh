#!/bin/bash

lin="==============================="
var="0"

echo $lin
echo "Iniciando compilação..."
echo $lin


gcc q7.c controller/*.c view/*.c model/*.c global/*.c -o q7
echo $lin
echo  "Digite: 1 para rodar ou q para sair: "
read var

case $var in 
1)
    ./q7
    echo $lin
    echo "Aplicação finalizada!" ;;
q)
    exit ;;
esac
