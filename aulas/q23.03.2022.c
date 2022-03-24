/*Somar, subtrair e multiplicar*/

#include <stdio.h>

int soma(int n1, int n2){
  return n1 + n2;
}

int subtrai(int n1, int n2){
  return n1 - n2;
}

int multiplica(int n1, int n2){
  return n1 * n2;
}

void main(){
  int rSoma, rSubtracao, rMultiplicacao;
  int valor1, valor2;

  //Coletar entradas
  printf("Digite o primeiro numero: ");
  scanf("%d", &valor1);
  printf("Digite o segundo numero: ");
  scanf("%d", &valor2);

  //Calcular
  rSoma = soma(valor1, valor2);
  rSubtracao = subtrai(valor1, valor2);
  rMultiplicacao = multiplica(rSoma, rSubtracao);

  //Exibir saídas
  printf("A soma de %d com %d eh %d\n", valor1, valor2, rSoma);
  printf("A subtracao de %d por %d eh %d\n", valor1, valor2, rSubtracao);
  printf("A multiplicacao de %d por %d eh %d\n", rSoma, rSubtracao, rMultiplicacao);
}
