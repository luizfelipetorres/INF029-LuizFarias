#ifndef __UTIL_H
  #define __UTIL_H

//Bibliotecas padrão
  #include <string.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <locale.h>

//Bibliotecas locais
  #include "../model/objects.h"

//Constantes
  #define ROW 10
  #define COL 10
  #define BOATS 5

  //Diferenças entre sistemas operacionais 
  #ifdef __unix__
      #define CLEAR "clear"
  #else
      #define CLEAR "cls"
  #endif

//Módulos
  void espere(int segundos);

#endif