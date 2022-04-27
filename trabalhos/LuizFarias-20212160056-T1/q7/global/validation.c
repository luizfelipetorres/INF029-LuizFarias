#include "../model/util.h"
#include "validation.h"

void charToUpper(char *c){

}

int validarInput(char input[2]){

    if (input[0] >= 'a' && input[0] <= 'c')
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

