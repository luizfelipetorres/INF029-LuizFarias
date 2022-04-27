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
      left = (coluna - op ) < 0     ? -1 : coluna - op + 1;
      right = (coluna + op - 1) > 9 ? -1 : coluna + op - 1;
      top = (linha - op) < 0        ? -1 : linha - op + 1;
      down = (linha + op - 1) > 9   ? -1 : linha + op - 1;

      /*
      Percorrer o vetor e verificar se existe um barco no caminho
        Se existir, não permitir colocar o barco nessa posição
*/      
      left = verificarPonteiros(linha, left, LEFT, p);
      right = verificarPonteiros(linha, right, RIGHT, p);
      top = verificarPonteiros(coluna, top, TOP, p);
      down = verificarPonteiros(coluna, down, DOWN, p);

      imprimirMapaDados(p);
      printf("\nO seu barco iniciará no 0 e irá até uma das extremidades");
      printf("\nEscolha uma das extremidades:\n\n-> ");
      char c;
      scanf(" %1c", &c);

      if(c == LEFT) criaLista(linha, left, LEFT, p);
      else if (c == RIGHT) criaLista(linha, right, RIGHT, p);
      else if (c == TOP) criaLista(coluna, top, TOP, p);
      else if (c == DOWN) criaLista(coluna, down, DOWN, p);
      else printf("Valor inválido!");

      //Preencher todos com N e cria ligação na lista
      //Verificar se 'c' é válido (!= -1)
    }
    
    (*iPointer)--;
    p->tboats--;
  }while(p->tboats > 0); 
}

void criaLista(int inicio, int fim, Direcao direction, Player* p){
  int i = inicio;
  
  //Definir se o incremento será positivo ou negativo
  int incremento = (fim - inicio) > 0 ? 1 : -1;
  
/*Definindo ponteiros para os valores iniciais e finais
  parametro direction define o sentido do descolamento  
*/
  int* linha = (direction == RIGHT || direction == LEFT)   ? &inicio : &i;
  int* coluna = (direction == RIGHT || direction == LEFT)  ? &i : &inicio;
  
  Ponto* pInicio = &p->tabuleiro[*linha][*coluna];
  Ponto* ant = &p->tabuleiro[*linha][*coluna];

  i = fim;
  Ponto* pFim = &p->tabuleiro[*linha][*coluna];
  
  Ponto* atual;

  //Definir inicio
  pInicio->value = 'N';
  pInicio->prox = pFim;

  //Definir meio
  for (i = inicio + incremento; i != fim; i += incremento){
    p->tabuleiro[*linha][*coluna].prox = ant;
    p->tabuleiro[*linha][*coluna].value = 'N';
    ant = p->tabuleiro[*linha][*coluna].prox;
  }

  //Definir fim
  pFim->value = 'N';
  pFim->prox = ant; 
}

int verificarPonteiros(int inicio, int fim, Direcao direction, Player* p){
  int i;

  //Definir se o incremento será positivo ou negativo
  int incremento = (fim - inicio) > 0 ? 1 : -1;
  
/*Definindo ponteiros para os valores iniciais e finais
  parametro direction define o sentido do descolamento  
*/
  int* linha = (direction == RIGHT || direction == LEFT) ? &inicio : &i;
  int* coluna = (direction == RIGHT || direction == LEFT) ? &i : &inicio;  

  if (fim != -1){
    for(i = inicio; i != fim; i = i + incremento){
      if (p->tabuleiro[*linha][*coluna].prox != NULL){
        return -1;
        break;
      }
    }
    if (fim != -1) 
      p->tabuleiro[*linha][*coluna].value = direction;
  }
  return fim;
}