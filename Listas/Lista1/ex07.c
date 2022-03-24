#include <stdio.h>

#define ROW 3
#define COL 50

/*
Crie um programa que tenha uma função ler3Palavras. 
Essa função deve ler três palavras do
usuário e retornar as três palavras. 
A função main deve imprimir essas três palavras.
*/

void ler3Palavras(char m[][COL], int n){
//  Coletar entradas
    for (int i = 0, j = 1; i < n; i++, j++){
        //getchar();
        printf("Digite a %d palavra: ", j);
        fgets(m[i], COL, stdin);
    }
}

int main(){
//  Variáveis
    char palavras[ROW][COL];

//  Tratar dados
    ler3Palavras(palavras, ROW);

//  Exibir saídas
    for (int i = 0, j = 1; i < ROW; i++, j++){
        printf("A %d palavra foi: %s", j, palavras[i]);
    }
}