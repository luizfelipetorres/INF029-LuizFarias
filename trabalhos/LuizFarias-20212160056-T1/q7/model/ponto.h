    typedef struct ponto{
        char player;
        int posicao;
        struct ponto* h;
        struct ponto* v;
        struct ponto* d1;
        struct ponto* d2;
    } Ponto;

    typedef enum busca{
        H = 0,
        V = 1,
        D1 = 2,
        D2 = 3
    } Busca;

    typedef enum jogadores{
        EMPATE,
        PLAYER1,
        PLAYER2
    } Jogadores;


    typedef struct placar{
        int player1;
        int player2;
        int empate;
    }Placar;