#include "../model/util.h"
#include "validation.h"

void charToUpper(char *c){

}

int validarInput(char *input){
    int letra = 0, numero = 0;
    int validation = 0;

    if (input[0] >= 'a' && input[0] <= 'z')
        input[0] -= ('a' - 'A');

    if (
        (input[0] < 'A' || input[0] > 'J') ||
        (input[1] < '1' || input[1] > '10')    
    )
        return 0;
    input[0] -= 'A';
    input[1] -= '1';
    return 1;
}
