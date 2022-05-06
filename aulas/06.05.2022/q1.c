#include "q1.h"

int main(void){
  Carro c;

  lerDados(&c);

  imprimirDados(c);
  return 0;
}

void lerDados(Carro *c){
  printf("Insira a marca:");
  scanf("%s", c->marca);
  
  printf("Insira o modelo:");
  scanf("%s", c->modelo);
  
  printf("Insira o ano:");
  scanf("%d", &c->ano);
}

void imprimirDados(Carro c){
  printf("Marca: %s\n", c.marca);
  printf("Modelo: %s\n", c.modelo);
  printf("Ano: %d\n", c.ano);
}