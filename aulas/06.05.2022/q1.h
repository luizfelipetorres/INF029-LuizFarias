#ifndef __Q1_H
  #define __Q1_H

  #include <stdio.h>

  typedef struct carro{
    char marca[100];
    char modelo[100];
    int ano;
  } Carro;


  void imprimirDados(Carro c);
  
  void lerDados(Carro *c);

  
#endif