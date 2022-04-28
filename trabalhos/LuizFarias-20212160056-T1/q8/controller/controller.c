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
  p.barco = 0;

  return p;
}

void iniciarPartida(){
  Player* p1;
  Player* p2;
  Player* pAtirador;
  Player* pAlvo;
  int linha, coluna;
  char escolha[2];
  int rodada = 0;
  int validar;
  
  
  p1 = criaPlayer(1);
  p2 = criaPlayer(2);

  configuraTabuleiro(p1);
  configuraTabuleiro(p2);

  /*
  laço de partida
    verificar se rodada é par ou impar
      par = player1
      impar = player2
      usar ponteiro no player
      perguntar onde quer atirar
        Verificar se o barco é 1
        se for, trocar value para 

*/
  do{
    pAtirador = (rodada % 2 == 0) ? p1: p2;
    pAlvo = (rodada % 2 == 0) ? p2: p1;
    
    printMaps(p1, p2);
    printf("Vez do PLAYER %d\n\n-> ", pAtirador->value);
    scanf(" %2c", escolha);
    validar = validarInput(escolha, &linha, &coluna);
      
    rodada++;
  }while((p1->tboats > 0) && (p2->tboats > 0));
  
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

void totalBarcos(Player* p){
  p->tboats = (BOAT4 * 4) + (BOAT3 * 3) + (BOAT2 * 2) + BOAT1;
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

      if (p->tabuleiro[linha][coluna].barco != 0){
        imprimirDadosPlayer(p);
        printf("Já existe um barco nesse local!\n");
        validar = 0;
      }
    }while(validar == 0);

    //Se for um barco de uma posição
    if(op == 1){
      p->tabuleiro[linha][coluna].value = 'N';
      p->tabuleiro[linha][coluna].barco = 1;

    //Se tiver mais de uma posição
    }else{
      p->tabuleiro[linha][coluna].value = '0';

      //Definir se é possível colocar o barco na posição
      left = (coluna - op + 1) < 0     ? -1 : coluna - op + 1;
      right = (coluna + op - 1) > 9 ? -1 : coluna + op - 1;
      top = (linha - op + 1) < 0        ? -1 : linha - op + 1;
      down = (linha + op - 1) > 9   ? -1 : linha + op - 1;

      /*
      Percorrer o vetor e verificar se existe um barco no caminho
        Se existir, não permitir colocar o barco nessa posição
*/      
      left = verificarPonteiros(linha, coluna, left, LEFT, p);
      right = verificarPonteiros(linha, coluna, right, RIGHT, p);
      top = verificarPonteiros(linha, coluna, top, TOP, p);
      down = verificarPonteiros(linha, coluna, down, DOWN, p);

      imprimirMapaDados(p);
      printf("%d %d %d %d", left, right, top, down);
      printf("\nlinha: %d, coluna: %d", linha, coluna);
      printf("\nO seu barco iniciará no 0 e irá até uma das extremidades");
      printf("\nEscolha uma das extremidades:\n\n-> ");
      char c;
      scanf(" %1c", &c);

      if(c == LEFT) criarBarco(linha, coluna, left, LEFT, p);
      else if (c == RIGHT) criarBarco(linha, coluna, right, RIGHT, p);
      else if (c == TOP) criarBarco(linha, coluna, top, TOP, p);
      else if (c == DOWN) criarBarco(linha, coluna, down, DOWN, p);
      else printf("Valor inválido!");
      limparMapa(p, 'N');

      //Verificar se 'c' é válido (!= -1)
    }
    
    (*iPointer)--;
    p->tboats--;
  }while(p->tboats > 0);
  totalBarcos(p);
}

void criarBarco(int linha, int coluna, int fim, Direcao direction, Player* p){
  int i = (direction == LEFT || direction == RIGHT) ? coluna : linha;
  
  //Definir se o incremento será positivo ou negativo
  //int incremento = (fim - inicio) > 0 ? 1 : -1;
  int incremento = (direction == LEFT || direction == TOP) ? -1 : 1;
  
/*Definindo ponteiros para os valores iniciais e finais
  parametro direction define o sentido do descolamento  
*/
  int* pLinha = (direction == RIGHT || direction == LEFT)   ? &linha : &i;
  int* pColuna = (direction == RIGHT || direction == LEFT)  ? &i : &coluna;
  
  if (fim != -1){
    for(; i != (fim + incremento); i += incremento){
      p->tabuleiro[*pLinha][*pColuna].value = 'N';
      p->tabuleiro[*pLinha][*pColuna].barco = 1;
    }
  }
}

int verificarPonteiros(int linha, int coluna, int fim, Direcao direction, Player* p){
  int i = (direction == LEFT || direction == RIGHT) ? coluna : linha;

  //Definir se o incremento será positivo ou negativo
/*   int incremento = (fim - inicio) > 0 ? 1 : -1;
 */  

  int incremento = (direction == LEFT || direction == TOP) ? -1 : 1;

/*Definindo ponteiros para os valores iniciais e finais
  parametro direction define o sentido do descolamento  
*/
  int* pLinha  = (direction == RIGHT || direction == LEFT) ? &linha : &i;
  int* pColuna = (direction == RIGHT || direction == LEFT) ? &i : &coluna;  

  if (fim != -1){
    for(; i != fim; i += incremento){
      if (p->tabuleiro[*pLinha][*pColuna].barco != 0)
        return -1;
    }
    p->tabuleiro[*pLinha][*pColuna].value = direction;
  }
  return fim;
}