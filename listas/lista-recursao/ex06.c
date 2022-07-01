/*
Crie  um  programa  em  C,  que  contenha  uma  função  recursiva  que  receba  dois 
inteiros positivos k e n e calcule kn. Utilize apenas multiplicações. O programa principal 
deve  solicitar  ao  usuário  os  valores  de  k  e  n  e  imprimir  o  resultado  da  chamada  da 
função
*/

#include <stdio.h>

int exponencial(int base, int expoente){
    if (expoente > 0)
        return base * exponencial(base, expoente - 1);
    return 1;
}

int main(){
    int base, expoente;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    printf("Resutado: %d", exponencial(base, expoente));
    
    return 0;
}
