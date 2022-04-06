#include <stdio.h>
/*
Crie um programa que tenha uma função soma e a função main. 
A função main deve ler doisvalores, enviar para a função soma. 
A função soma deve realizar a soma e retornar o valor. 
A Função main deve imprimir o resultado da soma.
*/

int soma(int a, int b){
    return a + b;
}

int main(){
//  Variáveis
    int var1, var2, somatorio;

//  Coletar entradas
    printf("Digite o primeiro valor: ");
    scanf("%d", &var1);
    printf("Digite o segundo valor: ");
    scanf("%d", &var2);

//  Tratar dados
    somatorio = soma(var1, var2);

//  Exibir saídas
    printf("O somatorio dos dois valores eh %d.", somatorio);
}

