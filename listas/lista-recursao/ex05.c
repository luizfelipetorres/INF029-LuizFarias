/*
Crie  uma  função  recursiva  que  receba  um  número  inteiro  positivo  N  e  calcule  o 
somatório dos números de 1 a N.
*/

#include <stdio.h>

int somatorio(int n){
    if (n > 0)
        return n + somatorio(n - 1);
}

int main(){
    printf("%d", somatorio(10));
    return 0;
}
