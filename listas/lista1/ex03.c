#include <stdio.h>
/*
Faça um programa que tenha uma função que recebe um número inteiro 
e retorna o fatorial deste número. Esta função deve ainda verificar 
se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. 
A função main deve solicitar o valor do usuário e imprimir
o fatorial dele, ou se não é possível calcular o fatorial.
*/

int fatorial(int valor){
    if (valor < 0){
        //Em caso de erro, retornar zero
        return 0;
    } else if ((valor == 0) || (valor ==1)){
        //Fatorial de 0 = 1
        return 1;
    } else {
        //Usando recursividade
        return valor * fatorial(valor - 1);
    }
}

int main(){
//  Variáveis
    int valor;      
    int fat;

//  Coletar entradas
    printf("Digite um numero inteiro: ");
    scanf("%d", &valor);

//  Tratar dados
    fat = fatorial(valor);

//  Exibir saídas
    if (fat == 0){
        printf("O valor %d eh negativo e nao possui fatorial!\n", valor);
    }else{
        printf("O fatorial de %d eh %d.\n", valor, fat);
    }
}