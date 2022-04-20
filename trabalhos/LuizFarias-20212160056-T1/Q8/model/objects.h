#ifndef __OBJECTS_H
  #define __OBJECTS_H


/*Struct ponto
Deve ter ponteiros para os 4 lados
  se for um barco, ligar o ponteiro em uma lista encadeada
  Se não for ou se o barco não estiver virado para esse lado, apontar para NULL
  Conter um char com N, X, O

*/
  typedef struct ponto{
    
    struct ponto* left;
    struct ponto* right;
    struct ponto* top;
    struct ponto* down;
  } Ponto;
#endif