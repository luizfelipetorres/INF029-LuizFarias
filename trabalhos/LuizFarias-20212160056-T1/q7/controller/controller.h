#ifndef __CONTROLLER_H

    #define __CONTROLLER_H


/**
 * Função que percorre a lista no sentido indicado (h, v, d1 ou d2) 
 * 
 */
    int percorreLista(Ponto** p, int posicao, Busca b);

/**
 * Função que percorre todas as listas
 * 
 */
    int percorreListas(Ponto** p, int posicao);

/**
 * Inicializar o vetor principal usando malloc
 * 
 */
    void inicializaVetor(Ponto** p);

/**
 * Função que cria as coneções entre as listas
 * 
 */
    void configuraListas(Ponto** v);

int preenchePonto(Ponto* p, char player);

Placar* inicializaPlacar();

void incrementaPlacar(Placar* p1p2, Jogadores j);

int iniciarPartida(Placar* p1p2);

#endif
