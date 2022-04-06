#include <stdio.h>
#include <string.h>

/*
Faça um programa que leia os dados de nome, idade, 
sexo e cpf de 5 pessoas. 
Ao final imprima tudo. Utilize vetor e struct.
*/

#define TAM 2

int main(){
//  Variáveis
    struct tp_pessoa{
        char nome[40];
        int idade;
        char sexo;
        int cpf;
    } Pessoas[TAM]; 

    int i, j;

//  Coletar entradas
    for (i = 0, j = 1; i < TAM; i++, j++){
        printf("\n\nDigite o nome da %d pessoa: ", j);
        fgets(Pessoas[i].nome, 40, stdin);

        printf("Digite a idade da %d pessoa: ", j);
        scanf("%d", &Pessoas[i].idade);

        printf("Digite o sexo da %d pessoa (f/m): ", j);
        scanf("%s", &Pessoas[i].sexo);

        printf("Digite o cpf da %d pessoa: ", j);
        scanf("%d", &Pessoas[i].cpf);

        getchar();
    }

//  Exibir saídas
    for (i = 0, j = 1; i < TAM; i++, j++){
        printf("------------Pessoa %d\n", j);
        printf("Nome: %s", Pessoas[i].nome);
        printf("Idade: %d\n", Pessoas[i].idade);
        printf("Sexo: %c\n", Pessoas[i].sexo);
        printf("CPF: %d\n\n", Pessoas[i].cpf);
    }
}