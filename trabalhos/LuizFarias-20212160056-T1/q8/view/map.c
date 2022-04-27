#include "../global/util.h"
#include "menu.h"

void printMap(Player* p){
  printf("\n");
  int col = 'A';
  for(int i = 0; i < 10; i++){

    //Imprimir indice das colunas
    if (i == 0){
      printf("%7c", ' ');
      for (int k = 0; k < 10; k++){
        printf("%-6c", col++);
      }
      printf("\n");
    }

    //Imprimir indice da linha
    printf("%2d - ", i);
    for (int j = 0; j < 10; j++)
      printf("[ %c ] ", p->tabuleiro[i][j].value);
    printf("\n");
  }
printf("\n");
}

int imprimirDadosPlayer(Player* p){
  printf("\nTotal de barcos: \t%d\n", p->tboats);
  printf("Barco de tamanho 4: \t%d\n", p->boat4);
  printf("Barco de tamanho 3: \t%d\n", p->boat3);
  printf("Barco de tamanho 2: \t%d\n", p->boat2);
  printf("Barco de tamanho 1: \t%d\n\n", p->boat1);

  return p->tboats;
}

void imprimirLinha(){
  for (int i = 0; i < 64; i++)
    printf("=");
  printf("\n");
}

void imprimirPlayer(Player* p){
  imprimirLinha();
  printf("|%27cPlayer %d%27c|\n", ' ', p->value, ' ');
  imprimirLinha();
}

void imprimirMapaDados(Player* p){
    //header();
    system(CLEAR);
    imprimirPlayer(p);
    printMap(p);
    imprimirDadosPlayer(p);
}

void limparMapa(Player* p, char exceto){
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (p->tabuleiro[i][j].value != exceto)
        p->tabuleiro[i][j].value = ' ';
    }
  }
}

void printMaps(Player* p1, Player* p2){
  system(CLEAR);
  imprimirPlayer(p1);
  printMap(p1);
  printf("\n\n");
  imprimirPlayer(p2);
  printMap(p2);
  printf("\n\n");

}

