#! /bin/sh
gcc *.c global/*.c view/*.c controller/*.c -o q8 -Wall
echo "Aperta alguma tecla para iniciar o programa"
echo "OU"
echo "Aperte Ctrl + C para sair"
read var
./q8
#  model/*.c



