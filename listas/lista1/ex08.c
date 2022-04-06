#include <stdio.h>
#include <string.h>


/*
Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente.a
*/
struct tpNascimento{
    int dia;
    int mes;
    int ano;
};

struct tpCliente{
    char nome[40];
    struct tpNascimento nascimento;
    char cpf[15];
    char sexo;
};


void cadastrarCliente(struct tpCliente *c){
    printf("Digite o nome do cliente: \n");
    fgets((*c).nome, 40, stdin);
    int ln = strlen((*c).nome) - 1;
    //printf("ln = %d\nnome[%d] = %c", ln, ln, (*c).nome[ln]);
    if (((*c).nome[ln]) == '\n')
        (*c).nome[ln] = '\0';
    
    printf("Digite a data de nascimento do cliente (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &(*c).nascimento.dia, &(*c).nascimento.mes, &(*c).nascimento.ano);

    getchar();
    printf("Digite o CPF do cliente: (###.###.###-##): \n");
    fgets((*c).cpf, 15, stdin);
    getchar();

    printf("Digite o sexo do cliente (F/M): \n");
    scanf("%c", &(*c).sexo);
}

int main(){
//  Variáveis
    struct tpCliente cliente;

//  Coletar entradas
    cadastrarCliente(&cliente);

//  Exibir saídas
    printf("******DADOS DO CLIENTE******\n");
    printf("Nome:\t\t%s\n", cliente.nome);
    printf("Nascimento:\t%02d/%02d/%d\n", cliente.nascimento.dia,cliente.nascimento.mes,cliente.nascimento.ano);
    printf("CPF:\t\t%s\n", cliente.cpf);
    printf("Sexo:\t\t%c\n", cliente.sexo);

}

