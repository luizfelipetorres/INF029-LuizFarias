#include "../global/util.h"

void printEmptyMap(Player* p){
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
    printf("%2d - ", i+1);
    for (int j = 0; j < 10; j++)
      printf("[ %c ] ", p->tabuleiro[i][j].value);
    printf("\n");
  }
printf("\n");
}

int imprimirDadosPlayer(Player* p){
  printf("Total de barcos: \t\t%d\n", p->tboats);
  printf("Barco de tamanho 4: \t%d\n", p->boat4);
  printf("Barco de tamanho 3: \t%d\n", p->boat3);
  printf("Barco de tamanho 2: \t%d\n", p->boat2);
  printf("Barco de tamanho 1: \t%d\n", p->boat1);

  return p->tboats;
}