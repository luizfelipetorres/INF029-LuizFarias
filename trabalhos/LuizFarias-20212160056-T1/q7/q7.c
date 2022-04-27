#include "q7.h"
#include "model/util.h"
#include "view/view.h"
#include "controller/controller.h"
#include "global/validation.h"
//
int main(){
  Placar* p1p2;
  int vencedor;
  char op;

  imprimeAbertura();

  p1p2 = inicializaPlacar();

  do{
    vencedor= iniciarPartida(p1p2);
    if (vencedor == 0)
      printf("Empate!\n");
    else
      printf("Player %d venceu!", vencedor);
    printf("Jogar novamente? (s/n) \n");
    scanf(" %1[^\n]", &op); 

  }while(op != 'n' || op != 'N');

  return 0;
}
