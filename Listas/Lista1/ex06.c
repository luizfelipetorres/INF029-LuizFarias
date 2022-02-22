#include <stdio.h>

/*
Crie um programa que tenha uma função ler3Letras. 
Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve 
imprimir essas três letras
*/
#define QTD 3

int ler3Letras(char *c, int n){
    for (int i = 0; i < 3; i++){
        printf("Digite uma letra: ");
        scanf("%s", &c[i]);
    }
}

int main(){
//  Variáveis
    char letras[QTD];

//  Coletar entradas
    ler3Letras(letras, QTD);

//  Exibir saídas
    for (int i = 0; i < QTD; i++){
        printf("%d: %c\n", i, letras[i]);
    }
}