#include <stdio.h>

/*
Faça um programa que verifique se um número é primo
*/

int main(){
//  Variáveis
    int numero, iCont, divisores=0;

//  Coletar entradas
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

//  Tratar dados
    for (iCont = numero; iCont > 0; iCont--){
        if ((numero % iCont) == 0)
            divisores++;
    }
    
    if (divisores == 2){
        printf("Este numero tem %d divisores e eh primo!", divisores);
    } else {
        printf("Este numero tem %d divisores e NAO eh primo!", divisores);
    }
}