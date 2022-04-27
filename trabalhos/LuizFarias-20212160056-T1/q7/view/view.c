#include "../model/util.h"
#include "view.h"
#include "../global/validation.h"

void imprimeAbertura(){
  limpaTela();
  printf("\n\n");
  printf("TTTTTTTTTTT  |      III       |  KKK  KKK      \n");                
  printf("TTTTTTTTTTT  |                |  KKK KKK       \n");              
  printf("    TTT      |      III       |  KKKKK         \n");          
  printf("    TTT      |      III       |  KKKKK         \n");         
  printf("    TTT      |      III       |  KKK KKK       \n");          
  printf("    TTT      |      III       |  KKK  KKK      \n");         
  printf("-----------------------------------------------\n");               
  printf("TTTTTTTTTTT  |      AAA       |  KKK  KKK      \n");               
  printf("TTTTTTTTTTT  |     AAAAA      |  KKK KKK       \n");                 
  printf("    TTT      |    AAA AAA     |  KKKKK         \n");                 
  printf("    TTT      |   AAA   AAA    |  KKKKK         \n");                   
  printf("    TTT      |  AAAAAAAAAAA   |  KKK KKK       \n");                   
  printf("    TTT      | AAA       AAA  |  KKK  KKK      \n");                     
  printf("-----------------------------------------------\n");               
  printf("TTTTTTTTTTT  |    OOOOOO      |  EEEEEEEEEE    \n");                              
  printf("TTTTTTTTTTT  |   OOO  OOO     |  EEE           \n");                     
  printf("    TTT      |  OOO    OOO    |  EEEEEEE       \n");                         
  printf("    TTT      |  OOO    OOO    |  EEE           \n");                     
  printf("    TTT      |   OOO  OOO     |  EEE           \n");                      
  printf("    TTT      |    OOOOOO      |  EEEEEEEEEE    \n"); 
  imprimeCarregamento();
}

void imprimeCarregamento(){
    printf ("\n\nCarregando o sistema: \n\n");

    for (int i = 1; i <= 50; i++){

      for (int k = 0; k < i; k++){
        if (k==0)
          printf("%c", '|');
        printf("%s", (k == i - 1) ? "|||" : "=");
      }
      for (int m = i; m < 50; m++)
        printf(" ");
      printf ("  %d%%\r", i*2);
      fflush (stdout);

        for (int j = 0; j < i; j++){
            if (!j)
            printf("  ");

            printf ("%c", 2);
            espere(2);
        }
    }
}

void imprimeLogo(Placar* p1p2){
    limpaTela();
    printf("\n============================\n");
    printf("||                        ||\n");
    printf("||     JOGO DA VELHA      ||\n");
    printf("||                        ||\n");
    printf("||     Player 1 (X): %d    ||\n", p1p2->player1);
    printf("||     Player 2 (O): %d    ||\n", p1p2->player2);
    printf("||     Empate:       %d    ||\n", p1p2->empate);
    printf("||                        ||\n");
    printf("============================\n");
}

void imprimeJogo(Ponto **v){
  char *t = "\t";
  printf("\n\n\n");
  printf("%s   1   2   3 \n", t);  
  printf("%sA  %c | %c | %c \n", t, v[0]->player, v[1]->player, v[2]->player);
  printf("%s  ___|___|___\n", t);
  printf("%sB  %c | %c | %c \n", t, v[3]->player, v[4]->player, v[5]->player);
  printf("%s  ___|___|___\n", t);
  printf("%sC  %c | %c | %c \n", t, v[6]->player, v[7]->player, v[8]->player);
  printf("%s     |   |   \n\n\n", t);
}

void limpaTela(){
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif
}

void capturaInput(char * cel){
  int validation;
  
  do{
    printf("Insira uma jogada no formato LC (linha/coluna): ");
    scanf(" %2[^\n]", cel); //Pega os dois primeiros caracteres não nulos. Para quando encontra \n

    validation = validarInput(cel);
    if (!validation)
      printf("Valor digitado inválido! %c %c \n", cel[0], cel[1]);

  }while (!validation);

}