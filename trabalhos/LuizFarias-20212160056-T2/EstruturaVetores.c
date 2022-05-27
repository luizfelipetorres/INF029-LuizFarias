#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

/*Vetor de structs de tamanho TAM*/
Principal vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){
    Principal *v;
    No *aux, *ant;

    // se posição é um valor válido {entre 1 e 10}
    if (posicao < 1 || posicao > 10){ 
        return POSICAO_INVALIDA;
    
    }else{
        //Utilizar ponteiro para facilitar leitura
        v = &vetorPrincipal[posicao - 1];
   
        // a posicao pode já existir estrutura auxiliar
        if (v->tamanho != 0) return JA_TEM_ESTRUTURA_AUXILIAR;
    } 

    // o tamanho nao pode ser menor que 1
    if (tamanho < 1) return TAMANHO_INVALIDO;
  
    // deu tudo certo, crie
    else{
        v->tamanho = tamanho;

        //Iterar lista alocando espaços
        for (int i = 0; i < tamanho; i++){
            aux = (No*) malloc(sizeof(No));

            //Se aux for NULL, retorne
            if (aux == NULL)
                return SEM_ESPACO_DE_MEMORIA;

            //Se for a primeira iteração, apontar lista para aux
            if (i == 0)
                v->lista = aux;
            else
                ant->prox = aux;
            
            ant = aux;
            aux = aux->prox; 
        }
        return SUCESSO;
    }
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
    No *aux;

    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    //Definir ponteiro para facilitar leitura
    Principal *v = &vetorPrincipal[posicao - 1];

    // testar se existe a estrutura auxiliar
    if (v->tamanho != 0){

        //Verificar se tem espaço
        if (v->tamanho > v->qtdElementos){
            
            //Navegar até a última posição não preenchida
            aux = v->lista;
            int i = 0;
            while(i++ < v->qtdElementos)
                aux = aux->prox;

            //Preencher
            aux->conteudo = valor;
            v->qtdElementos++;
            return SUCESSO;

        }else
            return SEM_ESPACO;

    }else
        return SEM_ESTRUTURA_AUXILIAR;


}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    //Usar ponteiro para facilitar leitura
    Principal *v = &vetorPrincipal[posicao - 1];
    int verificar = verificarPosicaoTamanho(posicao - 1, v->tamanho);

    if (verificar != SUCESSO)
        return verificar;
    
    else{
        v->qtdElementos--;
        return SUCESSO;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    Principal *v = &vetorPrincipal[posicao - 1];
    No *aux = v->lista;
    int encontrado = 0;
    int i;
    int verificar = verificarPosicaoTamanho(posicao - 1, v->tamanho);

    if (verificar != SUCESSO)
        return verificar;

    for(i = 0; i < v->qtdElementos; i++, aux = aux->prox){

        //Se encontrar o valor, definir 'encontrado' com valor de i
        if (!encontrado)
            encontrado = (aux->conteudo == valor ? 1: 0);

        //Caso o valor tenha sido encontrado
        if (encontrado)
            aux->conteudo = aux->prox->conteudo;
    }

    if (encontrado){
        v->qtdElementos--;
        return SUCESSO;
    }else
        return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    return (posicao > 0) && (posicao < 11);
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    Principal *v = &vetorPrincipal[posicao - 1];
    No *aux;
    int verificar = verificarPosicaoTamanho(posicao - 1, v->tamanho);

    if (verificar != SUCESSO)
        return verificar;

    aux = v->lista;
    for (int i = 0; i < v->qtdElementos; i++, aux = aux->prox)
        vetorAux[i] = aux->conteudo;
    
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    Principal *v = &vetorPrincipal[posicao - 1];
    No *aux;
    int i, j;
    int verificar = verificarPosicaoTamanho(posicao - 1, v->tamanho);
    
    if (verificar != SUCESSO)
        return verificar;

    //Insertion
    aux = v->lista;
    vetorAux[0] = aux->conteudo;
    for (i = 0; i < v->qtdElementos; i++, aux = aux->prox){

        for (j = i - 1; (j >= 0) && (vetorAux[j] >= aux->conteudo); j--)
            vetorAux[j + 1] = vetorAux[j];
        
        vetorAux[j+1] = aux->conteudo;
    }
    return SUCESSO;
}

/*
Objetivo: percorrer vetorPrincipal e verificar se todas as estruturas estão vazias

Retorno: 
1 se for verdade
0 se for falso
*/
int todasEstruturasVazias(){
    Principal *v;
    int contadorVazias = 0;

    for (int i = 0; i < TAM; i++){
        v = &vetorPrincipal[i];
        contadorVazias += (v->qtdElementos == 0 ? 1 : 0);
    }
    return contadorVazias == 10;
}


/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    Principal *v;
    No *n;
    int k = 0;

    if (todasEstruturasVazias())
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (int i = 0; i < TAM; i++){

       //Simplificar a leitura
        v = &vetorPrincipal[i];

        //Verificar se a estrutura está vazia
        if (v->qtdElementos != 0){
            
            //Preencher
            n = v->lista;
            for (int j = 0; j < v->qtdElementos; j++, n = n->prox)
                vetorAux[k++] = n->conteudo;
        }
    }
    return SUCESSO;
}

/*
Objetivo: juntar (merge) dois vetores ordenados

Retorno: tamanho do vetor resultante
*/
int *intercala(int *vetor1, int tamanho1, int *vetor2, int tamanho2){
    int tamanhoTotal = tamanho1 + tamanho2;
    int i, j, k;
    j = k = 0;
    int *vetorResultante = malloc(sizeof(int) * tamanhoTotal);

    for (i = 0; i < tamanhoTotal; i++){

        //Se finalizar o vetor1
        if (j == tamanho1){
            vetorResultante[i] = vetor2[k++];
        
        //Se finalizar o vetor2
        }else if (k == tamanho2){
            vetorResultante[i] = vetor1[j++];

        //Se vetor1 for menor ou igual
        }else if (vetor1[j] <= vetor2[k]){
            vetorResultante[i] = vetor1[j++];
        
        //Vetor2 for menor
        }else
            vetorResultante[i] = vetor2[k++];
    }
    return vetorResultante;
}
/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    Principal *v;
    int *aux;
    int tamanho = 0;
    int *resultante;

    if (todasEstruturasVazias())
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (int i = 0; i < TAM; i++){

        v = &vetorPrincipal[i];
        if (v->qtdElementos != 0){

            tamanho += v->qtdElementos;
            aux = malloc(sizeof(int) * v->qtdElementos);

            getDadosOrdenadosEstruturaAuxiliar(i + 1, aux);
            resultante = intercala(aux, v->qtdElementos, resultante, tamanho - v->qtdElementos);
        }
    }

    for (int i = 0; i < tamanho; i++)
        vetorAux[i] = resultante[i];

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' 
para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. 
O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    Principal *v = &vetorPrincipal[posicao - 1];
    No *aux, *alvo;
    int tTotal = novoTamanho + v->tamanho;
    int i;

    int verificar = verificarPosicaoTamanho(posicao - 1, v->tamanho);
    if (verificar != SUCESSO)
        return verificar;

    //Verificar ses o novo tamanho é inválido
    if (tTotal < 1)
        return NOVO_TAMANHO_INVALIDO;

    //Se o novoTamanho for negativo, diminuir
    if (novoTamanho < 0){

        //Navegar até a nova posição
        aux = v->lista;
        for (i = 0; i < tTotal; i++, aux = aux->prox);

        //Apagar posições seguintes
        for (; i < v->tamanho; i++, aux = alvo){
            alvo = aux->prox;
            free(aux);
        }
        v->qtdElementos = tTotal;

    }else if (novoTamanho > 0){

        //Navegar até o tamanho atual
        aux = v->lista;
        for (i = 1; i < v->tamanho; i++, aux = aux->prox);

        //Criar posisões
        for (; i <= novoTamanho; i++, aux = aux->prox){
            alvo = malloc(sizeof(No));
            alvo->conteudo = 13;
            aux->prox = alvo;
        }
    }
    v->tamanho = tTotal;
    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    Principal *v = &vetorPrincipal[posicao - 1];
    int verificar = verificarPosicaoTamanho(posicao - 1, v->tamanho);
    if (verificar != SUCESSO)
        return verificar;

    return v->qtdElementos;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No *montarListaEncadeadaComCabecote(){
    Principal *v;
    No *aux;
    No *inicio = NULL;
    No *fim = NULL;

    //Percorrer vetorPrincipal
    for (int i = 0; i < TAM; i++){

        v = &vetorPrincipal[i];

        //Se houver elementos, realocar inicio e incrementar
        if (v->qtdElementos != 0){

            aux = v->lista;
            for (int j = 0; j < v->qtdElementos; j++, aux = aux->prox)
                insere(&inicio, aux->conteudo, &fim);
        }
    }
    return inicio; 
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    No* n = inicio;

    for (int i = 0; n != NULL; i++, n = n->prox)
        vetorAux[i] = n->conteudo;
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio){
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void inicializar(){
    for (int i = 0; i < TAM; i++){
        vetorPrincipal[i].lista = NULL; 
        vetorPrincipal[i].qtdElementos = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar(){
    Principal *v;
    No *aux;
    No *prox;
    No *fim = NULL;

    for (int i = 0; i < TAM; i++){
        v = &vetorPrincipal[i];

        //Se a lista não estiver vaziar, percorrer e esvaziar
        if (v->tamanho != 0){

            aux = v->lista;
            for (int j = 0; j < v->tamanho; j++){
                prox = aux->prox;
                free(aux);
                aux = prox;
            }
            v->lista = NULL;
            v->tamanho = v->qtdElementos = 0;
        }
    }
}

int verificarPosicaoTamanho(int p, int t){

    //Definir ponteiro para facilitar leitura
    Principal *v = &vetorPrincipal[p];

    if (p < 0 || p > 9) 
        return POSICAO_INVALIDA;

    else if (v->tamanho == 0)
        return SEM_ESTRUTURA_AUXILIAR;
    
    else if (t < 1)
        return TAMANHO_INVALIDO;

    else if (v->qtdElementos == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    else
        return SUCESSO;
}

void insere(No **inicio, int valor, No **fim){
    No *novo = malloc(sizeof(No));
    
    novo->conteudo = valor;
    novo->prox = NULL;
    if (*inicio == NULL){
        *inicio = novo;
        *fim = novo;
    }else{
        (*fim)->prox = novo;
        *fim = novo;
    }
}