#include <stdio.h>
/*
Crie um programa que tenha uma função subtrai e a função main. 
A função main deve ler três valores, enviar para a função subtrai. 
A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. 
A Função main deve imprimir o resultado da subtração
*/

int subtracao(int a, int b, int c){
    return a - b - c;
}

int main(){
//  Variáveis
    int valores[3];
    int i, j, resultado;

//  Coletar entradas
    for (i = 0, j = 1; i < 3; i++, j++){
        printf("Digite o %d valor: ", j);
        scanf("%d", &valores[i]);
    }

//  Tratar dados
    resultado = subtracao(valores[0], valores[1], valores[2]);

//  Exibir saídas
    printf("O resultado da subtracao eh %d.", resultado);
}