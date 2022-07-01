/*
1) Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro N.
*/

#include <stdio.h>

int fatorial(int n){
    if (n <= 1){
        return 1;
    }else{
        return n * fatorial(n - 1);
    }
}

int main(){
    printf("%d", fatorial(5));
    return 0;
}