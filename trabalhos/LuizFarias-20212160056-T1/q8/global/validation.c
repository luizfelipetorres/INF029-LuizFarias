#include "validation.h"

int validarInput(char *input){
    int letra = 0, numero = 0;
    int validation = 0;

    if (input[0] >= 'a' && input[0] <= 'z')
        input[0] -= ('a' - 'A');

    if (
        (input[0] < 'A' || input[0] > 'C') ||
        (input[1] < '1' || input[1] > '3')    
    )
        return 0;
    input[0] -= 'A';
    input[1] -= '1';
    return 1;
}
