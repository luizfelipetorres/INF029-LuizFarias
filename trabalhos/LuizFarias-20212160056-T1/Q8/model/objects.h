#ifndef __OBJECTS_H
  #define __OBJECTS_H

  #define TOTAL_BOATS 5
  #define BOAT4 1
  #define BOAT3 1
  #define BOAT1 3
  #define BOAT2 (TOTAL_BOATS - BOAT4 - BOAT3 - BOAT1)

/*Struct ponto
Deve ter ponteiros para os 4 lados
  se for um barco, ligar o ponteiro em uma lista encadeada
  Se não for ou se o barco não estiver virado para esse lado, apontar para NULL
  Conter um char com N, X, O

*/

  typedef enum tpValue{
    V=' ',  //Espaço vazio
    N='N',  //Navio posicionado
    O='O',  //Navio abatido
    X='X'   //Tiro inválido
  } Value;

  typedef enum enumPlayer{
    P1 = 1,
    P2 = 2
  } ePlayer;

  typedef struct ponto{
    Value value;
    struct ponto* left;
    struct ponto* right;
    struct ponto* top;
    struct ponto* down;
  } Ponto;

  typedef struct player{
    ePlayer value;
    int tboats;
    int boat4;
    int boat3;
    int boat2;
    int boat1;
    Ponto tabuleiro[10][10];
  } Player;

  
#endif