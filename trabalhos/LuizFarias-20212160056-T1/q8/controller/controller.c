#include "../global/util.h"
#include "../model/objects.h"
#include "../view/map.h"
#include "../view/menu.h"
#include "controller.h"

Ponto criarPonto(){
  Ponto p;
  //p = malloc(sizeof(Ponto));
  p.value = ' ';
  p.prox = NULL;

  return p;
}

void iniciarPartida(){
  Player* p1;
  Player* p2;

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

  configuraTabuleiro(p1);

  
  
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

void configuraTabuleiro(Player* p){
  int validar = 0;
  int op;
  int* iPointer;
  char posicao[2];


  //Repetir enquanto ainda houver barcos
  do{
    header();
    printEmptyMap(p);
    imprimirDadosPlayer(p);

    //Laço para escolher o tamanho do barco e atribuir a quantidade a um ponteiro
    do{
      printf("\nEscolha o tamanho do barco que você quer inserir: \n\n-> ");
      scanf(" %d", &op);
  
      iPointer = NULL;
      switch(op){
        case 4:
            iPointer = p->boat4 > 0 ? p->boat4: NULL;
          break;
        case 3:
            iPointer = p->boat3 > 0 ? p->boat3: NULL;
          break;
        case 2:
            iPointer = p->boat2 > 0 ? p->boat2: NULL;
          break;
        case 1:
            iPointer = p->boat1 > 0 ? p->boat1: NULL;
          break;
          default:
            printf("Tamanho do barco inválido!");
            break;
      }
      
      validar = (iPointer != NULL) ? 1: 0;
    }while(validar == 0);

    //Laço para escolher a posição inicial do barco
    do{
      printf("Escolha a posição inicial (linha e coluna)do seu barco de tamanho %d\n\n-> ", op);
      scanf(" %2[^\n]", posicao);

    }while(validar == 0);

  }while(p->tboats > 0); 
}