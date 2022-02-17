//Faça um programa que leia a idade de duas pessoas e imprima a soma das idades
#include <stdio.h>

int main(){
    int idade1, idade2, soma;

    printf("Digite a idade da primeira pessoa: ");
    scanf("%d", &idade1);
    printf("Digite a idade da segunda pessoa: ");
    scanf("%d", &idade2);

    soma = idade1 + idade2;
    printf("A soma das idades é igual a {%d}", soma);
}