/*
Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor
*/

#include <stdio.h>

int main(){
    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18){
        printf("Vc eh adulto!");
    } else {
        printf("Vc nao eh adulto!");
    }
}