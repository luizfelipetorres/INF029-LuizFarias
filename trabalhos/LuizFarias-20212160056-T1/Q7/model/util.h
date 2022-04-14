#ifndef __UTIL_H

    //importações
    #include <string.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "ponto.h"


    //Definições
    #define __UTIL_H
    #define TAM 9

    void espere(int segundos);


    //Diferenças entre sistemas operacionais 
    #ifdef __unix__
        #define CLEAR "clear"
    #else
        #define CLEAR "cls"
    #endif
#endif //__UTIL_H