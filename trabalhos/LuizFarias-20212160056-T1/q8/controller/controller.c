#include "../global/util.h"
#include "../model/objects.h"
#include "../view/map.h"
#include "../view/menu.h"
#include "controller.h"
#include "../global/validation.h"

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
  int linha;
  int coluna;
  char posicao[2];
  int left, right, top, down;
  Ponto* inicio;
  Ponto* fim;


  //Repetir enquanto ainda houver barcos para colocar no mapa
  do{

    //Laço para escolher o tamanho do barco e atribuir a quantidade a um ponteiro
    imprimirMapaDados(p);
    do{
      printf("Escolha o tamanho do barco que você quer inserir: \n\n-> ");
      scanf(" %1d", &op);
  
      iPointer = NULL;
      switch(op){
        case 4:
            iPointer = p->boat4 > 0 ? &p->boat4: NULL;
          break;
        case 3:
            iPointer = p->boat3 > 0 ? &p->boat3: NULL;
          break;
        case 2:
            iPointer = p->boat2 > 0 ? &p->boat2: NULL;
          break;
        case 1:
            iPointer = p->boat1 > 0 ? &p->boat1: NULL;
          break;
          default:
            imprimirMapaDados(p);
            printf("Tamanho do barco inválido!\n");
            break;
      }
      
      validar = (iPointer != NULL) ? 1: 0;
    }while(validar == 0);

    //Laço para escolher a posição inicial do barco
    imprimirMapaDados(p);
    do{
      printf("Escolha a posição inicial do seu barco de tamanho %d\n(linha de 1 a 10 e coluna de A a J)\n\n-> ", op);
      scanf(" %2[^\n]", posicao);
      validar = validarInput(posicao, &linha, &coluna);

      if (validar == 0){
        imprimirMapaDados(p);
        printf("Opção inválida!\n");
      }
    }while(validar == 0);


    /*
      Verificar se já existe algum barco no local pelo ponteiro

    */
    if (p->tabuleiro[linha][coluna].prox != NULL)
      printf("Já existe um barco nesse local!\n");
    else{
      p->tabuleiro[linha][coluna].value = '0';

      //Definir se é possível colocar o barco na posição
      left = (coluna - op ) < 0     ? 0 : coluna - op + 1;
      right = (coluna + op - 1) > 9 ? 0 : coluna + op - 1;
      top = (linha - op) < 0        ? 0 : linha - op + 1;
      down = (linha + op - 1) > 9   ? 0 : linha + op - 1;


      if (left)
        for(int i = coluna - 1; i >= left; i--)
          p->tabuleiro[linha][i].value = '1';

      if (right)
        for (int i = coluna + 1; i <= right; i++)
          p->tabuleiro[linha][i].value = '2';

      if (top)
        for (int i = linha - 1; i >= top; i--)
          p->tabuleiro[i][coluna].value = '3';
          
      if (down)
        for (int i = linha + 1; i <= down; i++)
          p->tabuleiro[i][coluna].value = '4';

      imprimirMapaDados(p);
      printf("\nO seu barco iniciará no 0 e irá até uma das extremidades");
      printf("\nEscolha uma das extremidades:\n\n-> ");
      scanf(" %1c", &op);

/*       Ponto* aux;
      for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
          p->tabuleiro[i][j].prox = p->tabuleiro[i][j].value = op ? 
        }
      } */



      
      

/* 
      printf("%d %d %d %d", left, right, top, down);
      getchar();
      getchar();
 */
    }

  }while(p->tboats > 0); 
}

int preencherPossibilidades(int linha, int coluna, int left, int right, int top, int down, Player* p){

}

int preencheHorizontal(int inicio, int *fim, int incremento, Player* p){
  int tipo;
  

  if (fim){
    for(int i = inicio + incremento; i >= fim; i = i + incremento){
      if (p->tabuleiro[inicio][i].prox != NULL){
        *fim = 0;
        break;
      }
      p->tabuleiro[inicio][i].value = '1';
    }

    if (!fim)
      for(int i = inicio + incremento; i >= fim; i = i + incremento)
        p->tabuleiro[inicio][i].value = ' ';
  }
  
}

int verificarPonteiros(int inicio, int fim, int horizontal, Player* p){
  int incremento = (fim - inicio) > 0 ? 1 : -1;
  
  if (horizontal){
    for (int i = inicio + incremento; i != fim; i = i + incremento){
      if (p->tabuleiro[inicio][i].prox != NULL)
        return 0;
    }
  }else{
    for (int i = inicio + incremento; i != fim; i = i + incremento){
      if (p->tabuleiro[i][inicio].prox != NULL)
        return 0;
    }
  }
  return 1;

}