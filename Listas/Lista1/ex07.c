#include <stdio.h>


/*
Crie um programa que tenha uma função ler3Palavras. 
Essa função deve ler três palavras do
usuário e retornar as três palavras. 
A função main deve imprimir essas três palavras.
*/
#define QTD 3

void ler3Palavras(char palavras[][QTD], int n){

    for (int i = 0; i < QTD; i++){
        printf("Escreva uma palavra: ");
        scanf("%s", palavras[i]);
    }
}

int main(){
//  Variáveis
    char vetor[0][QTD];

//  Coletar entradas
    ler3Palavras(vetor, QTD);

//  Tratar dados
    for (size_t i = 0; i < QTD; i++){
        printf("Vc digitou %s.\n", vetor[i]);
    }
    

//  Exibir saídas


}