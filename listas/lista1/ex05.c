#include <stdio.h>
/*
Crie um programa que tenha uma função ler4Numeros. 
Essa função deve ler quatro números do
usuário e retornar os quatro números. 
A função main deve imprimir esses quatro números. Utilize
struct para fazer o retorno
*/

struct valores {
    int v1, v2, v3, v4;
};

//Definindo a função que recebe uma struct do tipo valores
void ler4Numeros(struct valores *estrutura){
    
    //Coletar entradas usando referência
    printf("Digite um valor: ");
    scanf("%d", &(*estrutura).v1);

    printf("Digite um valor: ");
    scanf("%d", &(*estrutura).v2);

    printf("Digite um valor: ");
    scanf("%d", &(*estrutura).v3);

    printf("Digite um valor: ");
    scanf("%d", &(*estrutura).v4);
}

void main(){
    struct valores n;
    
    //Passando a struct para a função
    ler4Numeros(&n);

    //Imprimindo
    printf("\nvalor 1: %d\n", n.v1);
    printf("valor 2: %d\n", n.v2);
    printf("valor 3: %d\n", n.v3);
    printf("valor 4: %d\n", n.v4);
}