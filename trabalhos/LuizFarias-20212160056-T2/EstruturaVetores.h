#ifndef TRABALHO2_ESTRUTURAVETORES_H
    #define TRABALHO2_ESTRUTURAVETORES_H

    // enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
    // as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
    // as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
    // constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
    enum { 
        TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, 
        NOVO_TAMANHO_INVALIDO, 
        NUMERO_INEXISTENTE,
        ESTRUTURA_AUXILIAR_VAZIA, 
        TAMANHO_INVALIDO, 
        SEM_ESPACO_DE_MEMORIA, 
        POSICAO_INVALIDA,
        JA_TEM_ESTRUTURA_AUXILIAR, 
        SEM_ESTRUTURA_AUXILIAR, 
        SEM_ESPACO, 
        SUCESSO 
    };

/*
Struct que guarda os conteúdos e um ponteiro para o próximo item
Usado para formar uma lista encadeada
*/
    typedef struct reg {
        int conteudo;
        struct reg *prox;
    } No;


/*
Struct usada no vetor principal. 
    -Aponta para uma lista do tipo 'No' 
    Possui unsisgned int tamanho e qtdELementos
*/
    typedef struct principal {
        No *lista;
        unsigned int tamanho;
        unsigned int qtdElementos;

    } Principal;
    
    int criarEstruturaAuxiliar(int posicao, int tamanho);
    int inserirNumeroEmEstrutura(int posicao, int valor);
    int excluirNumeroDoFinaldaEstrutura(int posicao);
    int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
    int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
    int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
    int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
    int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
    int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
    int getQuantidadeElementosEstruturaAuxiliar(int posicao);
    No *montarListaEncadeadaComCabecote();
    void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
    void destruirListaEncadeadaComCabecote(No **inicio);
    void inicializar();
    void finalizar();
    void dobrar(int *x);

    /*Objetivo: verificar estrutura auxiliar usando posição de vetorPrincipal e tamanho
    
    Retornos possíveis:
        POSICAO_INVALIDA            Se a posição for inválida
        SEM_ESTRUTURA_AUXILIAR      Se não houver estrutura
        TAMANHO_INVALIDO            se o tamanho for inválido
        ESTRUTURA_AUXILIAR_VAZIA    se a estrutura estiver vazia
        SUCESSO                     Se estiver tudo OK
    */
    int verificarPosicaoTamanho(int p, int t);
    int todasEstruturasVazias();
    int *intercala(int *vetor1, int tamanho1, int *vetor2, int tamanho2);

void insere(No **inicio, int valor, No **fim);



#endif  // TRABALHO2_ESTRUTURAVETORES_H
