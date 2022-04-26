#ifndef __VIEW_H
    
    #define __VIEW_H

/**
 * Função que Limpa a tela e imprime a logo do jogo
 * 
 */
    void imprimeLogo(Placar* p1p2);

/**
 * Função que imprime o tabuleiro 
 * 
 */
    void imprimeJogo(Ponto **v);

/**
 * FUnção que limpa a tela (indeppendente do sistema operacionai)
 * 
 */
    void limpaTela();


/**
 * Função que captura o input do usuário 
 * 
 */
void capturaInput(char * cel);

void imprimeAbertura();

void imprimeCarregamento();

#endif //__VIEW_H
