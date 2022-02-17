/*
Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor. 
O programa deve repetir essa ação até que uma idade negativa seja informada
*/

#include <stdio.h>

int main(){
//  Variáveis
    int idade=0;

//  Coletar entradas
    do{
        printf("Digite a sua idade: ");
        scanf("%d", &idade);
        
        if (idade>=18){
            printf("Vc eh adulto!\n");    
        } else if (idade >=0){
            printf("Vc nao eh adulto!\n");
        }
    } while (idade >=0);
    printf("Programa finalizado com valor negativo.");
}