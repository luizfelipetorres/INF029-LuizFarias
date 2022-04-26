#ifndef __CONTROLER_H
  #define __CONTROLER_H

  //Funções
  Ponto criarPonto();
    
  void iniciarPartida();

Player* criaPlayer(ePlayer n);

void configuraTabuleiro(Player* p);

int preencheBarco(int inicio, int fim, int incremento, Player* p);

#endif