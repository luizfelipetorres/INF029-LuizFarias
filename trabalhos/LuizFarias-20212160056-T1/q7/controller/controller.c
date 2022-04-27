#include "../model/util.h"
#include "controller.h"
#include "../view/view.h"

int percorreLista(Ponto** p, int posicao, Busca b){
  Ponto *atual, *anterior;
  int igualdade = 0;


  atual = p[posicao]; 

  do{
    anterior = atual;
    
    switch (b){
      case H:  atual = atual->h;  break;
      case V:  atual = atual->v;  break;
      case D1: atual = atual->d1; break;
      case D2: atual = atual->d2; break;
    }

    if (anterior == atual) return 0;
    if(anterior->player != atual->player) return 0; 
    
    //atual = atual->h;
    (anterior->player == atual->player) ? igualdade++ : igualdade--;
      
  }while (atual != p[posicao]);


  return (igualdade == 3) ? 1 : 0;
}

int percorreListas(Ponto** p, int posicao){
  for (int i = 0; i <= D2; i++){
    if (percorreLista(p, posicao, i) == 1) 
      return (p[posicao]->player == 'X') ? 1 : 2; 
  }
  return 0;
}

void configuraListas(Ponto** v){
    int horizontal, vertical, diagonal1, diagonal2;

    for (int i = 0; i < TAM; i++){

        //Definir regras para lista encadeada
        vertical = (i + 3) > 8 ? (i - 6) : (i + 3);
        horizontal = (i / 3 ) < ((i + 1) / 3) ? (i - 2) : (i + 1);

        diagonal1 = (i % 4 == 0) ? i + 4: -1;
        diagonal1 = (diagonal1 == 12) ? 0 :diagonal1;

        diagonal2 = ((i >= 2) && (i <= 6) && (i % 2 == 0)) ? (i + 2) : -1;
        diagonal2 = (diagonal2 == 8) ? 2 : diagonal2;

        v[i]->player = ' ';
        v[i]->posicao = i;
        v[i]->h = v[horizontal];
        v[i]->v = v[vertical];
        v[i]->d1 = (diagonal1 == -1) ? v[i]: v[diagonal1];
        v[i]->d2 = (diagonal2 == -1) ? v[i]: v[diagonal2];
    } 
}

int preenchePonto(Ponto* p, char player){
  if (p->player != ' ')
    return 0;
  else{
    p->player = player;
    return 1;
  }
}

void inicializaVetor(Ponto** p){
    
    for (int i = 0; i < TAM; i++)
        p[i] = malloc(sizeof(Ponto));

}

Placar* inicializaPlacar(){
  Placar* p;
  p =  malloc(sizeof(Placar));
  p->player1 = 0;
  p->player2 = 0;
  p->empate = 0;
  return p;
}

void incrementaPlacar(Placar* p1p2, Jogadores j){
  switch (j)
  {
  case PLAYER1:
    p1p2->player1++;
    break;

  case PLAYER2:
    p1p2->player2++;
    break;
  
  default:
    p1p2->empate++;
    break;
  }
}

int iniciarPartida(Placar* p1p2){
Ponto* v[TAM];
  //Placar * p1p2;
  char cel[2];
  int posicao = 0;
  char player;
  int op = -1;
  int jogadas = 0;

  inicializaVetor(v);

  configuraListas(v);

  int vencedor  = 0;
  
  for (int i = 0; (i < TAM && vencedor == 0); i++){    
    do{
      //Definir o jogador atual
      if (i % 2 == 0) player = 'X';else player = 'O';

      imprimeLogo(p1p2);
      imprimeJogo(v); 

      if ( op == 0)
        printf("Esse campo já foi preenchido!.\n");
      
      capturaInput(cel);
      posicao = cel[0] * 3 + cel[1];
      printf("posicao: %d\n", v[posicao]->posicao);
      op = preenchePonto(v[posicao], player);
      jogadas++;


    }while (op != 1);
    
    if (jogadas >= 5)
      vencedor = percorreListas(v, posicao);
  }

  incrementaPlacar(p1p2, vencedor);
  imprimeLogo(p1p2);
  imprimeJogo(v);

  return vencedor;
}