#include "q7.h"
#include "model/util.h"
#include "view/view.h"
#include "controller/controller.h"
#include "global/validation.h"

void main(){
  Placar* p1p2;
  int vencedor;
  char op;

  imprimeAbertura();

  p1p2 = inicializaPlacar();

/*   p1p2 = malloc(sizeof(Placar));
  p1p2->player1 = 0;
  p1p2->player2 = 0;
  p1p2->empate = 0; */

  do{
    vencedor= iniciarPartida(p1p2);
    if (vencedor == 0)
      printf("Empate!\n");
    else
      printf("Player %d venceu!", vencedor);
    printf("Jogar novamente? (s/n) \n");
    scanf(" %1[^\n]", &op); 

  }while(op != 'n' || op != 'N');
}
