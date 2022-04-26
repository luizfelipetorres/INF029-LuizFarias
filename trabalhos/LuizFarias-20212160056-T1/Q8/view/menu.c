#include "menu.h"
#include "../global/util.h"
#include "../controller/controller.h"

void menu(){
  int op=-1;
  
  header();
  printf("Escolha uma das opções: \n\n");
  printf("1 - Iniciar partida\n");
  printf("2 - Creditos\n");
  printf("0 - Sair\n\n");

  do{
    printf("\n-> ");
    scanf(" %d", &op);
    switch(op){
      case 1: iniciarPartida(); break;
  
      case 2: 
  
      case 0: exit(0); break;
  
      default:
        printf("Opção inválida! Tente novamente\n ");
        break;
    }
    
  }while(op != 0);
  
}

void header(){
  system(CLEAR);
  printf("\n=======================\n");
  printf("||                   ||\n");
  printf("||.: BATALHA NAVAL :.||\n");
  printf("||                   ||\n");
  printf("=======================\n\n");
}