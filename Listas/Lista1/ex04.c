#include <stdio.h>
/*
Crie um programa que tenha uma função ler 3 Numeros. 
Essa função deve ler três números do
usuário e retornar os três números. 
A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.
*/

#define T_VETOR 3

/*Definindo a função que recebe um vetor como referência

    *vetor: É a primeira posição do vetor (referencia)
    n:      É o tamanho do vetor
*/
void ler3Numeros(int *vetor, int n){
    
    //Coletar entradas
    for (int i = 0, j = 1; i < n; i++, j++){

        //Preenchendo o vetor v (passado por referência)
        printf("Digite o %d valor: ", j);
        scanf("%d", &vetor[i]);
    }
}

int main(){
    int v[T_VETOR];
    
    //Passando para a função com os dados do vetor
    ler3Numeros(v, T_VETOR);

    //Imprimir os valores do vetor
    for (int i = 0; i < T_VETOR; i++){
        printf("Posicao %d do vetor: %d\n", i, v[i]);
    }
}