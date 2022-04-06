#include <stdio.h>


/*
Faça um programa que leia 10 números do usuário e informe quais deles são primos. 
Além disso, mostre a soma de todos os números primos existentes.
*/

int main(){
//  Variáveis
    int numeros[10][2];
    int i, j, k, soma = 0;

//  Coletar entradas
    for (i = 0, k = 1; i < 10; i++, k++){
        printf("Digite o %d numero: ", k);
        scanf("%d", &numeros[i][0]);
        numeros[i][1] = 0;

        for (j = numeros[i][0]; j > 0; j--){
            if ((numeros[i][0] % j) == 0){
                numeros[i][1]++;
            }
        }
        if (numeros[i][1] == 2){
            printf("O numero %d eh primo!\n", numeros[i][0]);
            soma += numeros[i][0];
        }
    }

    printf("A soma de todos os primos digitados eh %d.", soma);

}   