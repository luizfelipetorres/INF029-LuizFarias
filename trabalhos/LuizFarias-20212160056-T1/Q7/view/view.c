#include "../model/util.h"
#include "view.h"
#include "../global/validation.h"

/*
       1   2   3 
	A  O | O | X 
	  __\|___|___
	B    |O  |   
	  ___|__\|___
	C    |   |O  
	     |   | \ 

       1   2   3 
	A    | O | X 
	  ___|___|___
	B O--|O--|O--   
	  ___|___|___
	C    |   |O  
	     |   |   


       1   2   3 
	A  X | O | X 
	  _|_|___|___
	B  X |O  |O     
	  _|_|___|___
	C  X |   |O  
	   | |   |   

printf("                                |                       |                         "); 
printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |         IIIII         |    KKKKK    KKKK        ");                                              
printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |         IIIII         |    KKKKK   KKKK         ");                                              
printf("              TTTTTT            |                       |    KKKKK  KKKK          ");                                              
printf("              TTTTTT            |         IIIII         |    KKKKK KKKK           ");                                             
printf("              TTTTTT            |         IIIII         |    KKKKKKKK             ");                                            
printf("              TTTTTT            |         IIIII         |    KKKKKKKKKK           ");                                              
printf("              TTTTTT            |         IIIII         |    KKKKK  KKKK          ");                                             
printf("              TTTTTT            |         IIIII         |    KKKKK   KKKK         ");                                            
printf("              TTTTTT            |         IIIII         |    KKKKK     KKKK       ");                                            
printf("     =================================================================================");
printf("     =================================================================================");
printf("                                |                       |                         "); 
printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |         AAAAA         |    KKKKK    KKKK        ");                                              
printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |        AAAAAAA        |    KKKKK   KKKK         ");                                              
printf("              TTTTTT            |       AAAA AAAA       |    KKKKK  KKKK          ");                                              
printf("              TTTTTT            |      AAAA   AAAA      |    KKKKK KKKK           ");                                             
printf("              TTTTTT            |     AAAA     AAAA     |    KKKKKKKK             ");                                            
printf("              TTTTTT            |    AAAAAAAAAAAAAAA    |    KKKKKKKKKK           ");                                              
printf("              TTTTTT            |   AAAAAAAAAAAAAAAAA   |    KKKKK  KKKK          ");                                             
printf("              TTTTTT            |  AAAA           AAAA  |    KKKKK   KKKK         ");                                            
printf("              TTTTTT            | AAAA             AAAA |    KKKKK     KKKK       ");                                            
printf("     =================================================================================");
printf("     =================================================================================");
printf("                                |                       |                         "); 
printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |       0000OOOO        |    EEEEEEEEEEEEEEE      ");                                                               
printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |      0000  OOOO       |    EEEEEEEEEEEEEEE      ");                                                               
printf("              TTTTTT            |     0000    OOOO      |    EEEEE                ");                                                     
printf("              TTTTTT            |    0000      OOOO     |    EEEEE                ");                                                    
printf("              TTTTTT            |   0000        OOOO    |    EEEEEEEEEE           ");                                                        
printf("              TTTTTT            |   0000        OOOO    |    EEEEEEEEEE           ");                                                          
printf("              TTTTTT            |    000O      OOOO     |    EEEEE                ");                                                    
printf("              TTTTTT            |     0000    OOOO      |    EEEEEEEEEEEEEEE      ");                                                              
printf("              TTTTTT            |      0000OOOOOO       |    EEEEEEEEEEEEEEE      ");                                                                    











*/

void imprimeAbertura(){
  char l1, l2, l3;
  l1 = 'X';
  l2 = 'O';
  l3 = 'T';


  limpaTela();
  printf("                                |                       |                         \n"); 
  printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |         IIIII         |    KKKKK    KKKK        \n");                                              
  printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |         IIIII         |    KKKKK   KKKK         \n");                                              
  printf("              TTTTTT            |                       |    KKKKK  KKKK          \n");                                              
  printf("              TTTTTT            |         IIIII         |    KKKKK KKKK           \n");                                             
  printf("              TTTTTT            |         IIIII         |    KKKKKKKK             \n");                                            
  printf("              TTTTTT            |         IIIII         |    KKKKKKKKKK           \n");                                              
  printf("              TTTTTT            |         IIIII         |    KKKKK  KKKK          \n");                                             
  printf("              TTTTTT            |         IIIII         |    KKKKK   KKKK         \n");                                            
  printf("              TTTTTT            |         IIIII         |    KKKKK     KKKK       \n");                                            
  printf("     =================================================================================\n");
  printf("                                |                       |                         \n"); 
  printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |         AAAAA         |    KKKKK    KKKK        \n");                                              
  printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |        AAAAAAA        |    KKKKK   KKKK         \n");                                              
  printf("              TTTTTT            |       AAAA AAAA       |    KKKKK  KKKK          \n");                                              
  printf("              TTTTTT            |      AAAA   AAAA      |    KKKKK KKKK           \n");                                             
  printf("              TTTTTT            |     AAAA     AAAA     |    KKKKKKKK             \n");                                            
  printf("              TTTTTT            |    AAAAAAAAAAAAAAA    |    KKKKKKKKKK           \n");                                              
  printf("              TTTTTT            |   AAAAAAAAAAAAAAAAA   |    KKKKK  KKKK          \n");                                             
  printf("              TTTTTT            |  AAAA           AAAA  |    KKKKK   KKKK         \n");                                            
  printf("              TTTTTT            | AAAA             AAAA |    KKKKK     KKKK       \n");                                            
  printf("     =================================================================================\n");
  printf("                                |                       |                         \n"); 
  printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |       0000OOOO        |    EEEEEEEEEEEEEEE      \n");                                                               
  printf("     TTTTTTTTTTTTTTTTTTTTTTTTT  |      0000  OOOO       |    EEEEEEEEEEEEEEE      \n");                                                               
  printf("              TTTTTT            |     0000    OOOO      |    EEEEE                \n");                                                     
  printf("              TTTTTT            |    0000      OOOO     |    EEEEE                \n");                                                    
  printf("              TTTTTT            |   0000        OOOO    |    EEEEEEEEEE           \n");                                                        
  printf("              TTTTTT            |   0000        OOOO    |    EEEEEEEEEE           \n");                                                          
  printf("              TTTTTT            |    000O      OOOO     |    EEEEE                \n");                                                    
  printf("              TTTTTT            |     0000    OOOO      |    EEEEEEEEEEEEEEE      \n");                                                              
  printf("              TTTTTT            |      0000OOOOOO       |    EEEEEEEEEEEEEEE      \n"); 
  //espere(3000);
  //getchar();
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
            espere(1);
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