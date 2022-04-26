#include "../global/util.h"
#include "../model/objects.h"
#include "../view/map.h"
#include "controller.h"

Ponto criarPonto(){
  Ponto p;
  //p = malloc(sizeof(Ponto));
  p.value = ' ';
  p.left = NULL;
  p.right = NULL;
  p.top = NULL;
  p.down = NULL;

  return p;
}

void iniciarPartida(){
  Player* p1;
  Player* p2;

  int op;
  p1 = criaPlayer(1);
  p2 = criaPlayer(2);
  


/*
  Iniciar configuração do mapa
    Imprimir quantidade de barcos do player
    perguntar qual o tamanho do barco que quer inserir
    verificar se o valor do barco escolhido é zero
      Se for zero
        pedir para inserir outro barco
      Se não for zero
        Barco escolhido é decrementado
        Imprimir barco com opções T D L R para escolha da posição
        Pedir para escolher entre T D L R
          Criar a lista encadeada na diração selecionada
*/

  
  do{
    header()
    printEmptyMap(p1);
    imprimirDadosPlayer(p1);
    printf("\nEscolha o tamanho do barco que você quer inserir: ");
    scanf(" %d", &op);
    
  }while(p1->tboats > 0);
  
  
}

Player* criaPlayer(ePlayer n){
  Player* p;
  p = malloc(sizeof(Player));
  
  p->value = n;
  p->tboats = TOTAL_BOATS;
  p->boat4 = BOAT4;
  p->boat3 = BOAT3;
  p->boat2 = BOAT2;
  p->boat1 = BOAT1;

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      p->tabuleiro[i][j] = criarPonto();

  return p;
}

