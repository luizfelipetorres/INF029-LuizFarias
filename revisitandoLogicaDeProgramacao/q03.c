/*
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas
*/

#include <stdio.h>

int main(){
    int valor1, valor2, auxiliar;

    printf("Digite o valor da primeira variavel: ");
    scanf("%d", &valor1);

    printf("Digite o valor da segunda variavel: ");
    scanf("%d", &valor2);

    auxiliar = valor1;
    valor1 = valor2;
    valor2 = auxiliar;

    printf("Valor1: %d\nValor2: %d", valor1, valor2);
}