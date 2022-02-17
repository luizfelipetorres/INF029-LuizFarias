/*
Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas 
**sem utilizar variável auxiliar
*/

#include <stdio.h>

int main(){
    int v1, v2;

    printf("Digite o valor da v1: ");
    scanf("%d", &v1);
    printf("Digite o valor da v2: ");
    scanf("%d", &v2);
    
    v1 = v2 - v1;
    v2 = v2 - v1;
    v1 = v2 + v1;

    printf("v1: %d\nv2: %d", v1, v2);
}