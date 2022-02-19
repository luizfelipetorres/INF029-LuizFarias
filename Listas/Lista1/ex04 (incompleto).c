#include <stdio.h>
/*
Crie um programa que tenha uma função ler 3 Numeros. 
Essa função deve ler três números do
usuário e retornar os três números. 
A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.
*/

int ler3Numeros(void){
    int vetor[3];

    //Coletar entradas
    for (int i = 0, j = 1; i < 3; i++, j++){
        printf("Digite o %d valor: ");
        scanf("%d", &vetor[i]);
    }
    return vetor[], 3;
}

int main(){
    int vetor[] = ler3Numeros();

    for (int i = 0; i < 3; i++){
        printf("%d\n");
    }
}