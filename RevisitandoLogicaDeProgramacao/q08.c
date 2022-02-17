#include <stdio.h>

/*
Faça um programa que calcula o fatorial de um número
*/

int main(){
//  Variáveis
    int numero, iCont;

//  Coletar entradas
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

//  Tratar dados
    for (iCont = (numero - 1); iCont > 1; iCont--){
        numero *= iCont;
    }
    
//  Exibir saídas
    printf("O fatorial desse numero eh %d.", numero);
}