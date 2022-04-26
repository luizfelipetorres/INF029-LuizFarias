#include "validation.h"
#include "util.h"

int validarInput(char *input, int* linha, int* coluna){
    int letra = 0, numero = 0, invalido = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++){
        if (input[i] >= 'a' && input[i] <= 'j'){
            letra++;
            *coluna = input[i] - 'a';
        }else if(input[i] >= 'A' && input[i] <= 'J'){
            letra++;
            *coluna = input[i] - 'A';
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            numero++;
            *linha = input[i] - '0';
        }
        else
            invalido++;  
    }
    /* 
    printf(
        "numero: %d\nletra: %d\ninvalido: %d\n",
        numero,
        letra,
        invalido
    ); 
    getchar();
    getchar();
     */

    return (numero == 1 && letra == 1 && invalido == 0);
}
