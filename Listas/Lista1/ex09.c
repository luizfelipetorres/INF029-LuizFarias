#include <stdio.h>
#include <string.h>

int formatarString(char *string);

/*
Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
imprimir os dados do cliente.a
*/
typedef struct {
    int dia;
    int mes;
    int ano;
} tpNascimento;

typedef struct {
    char nome[40];
    tpNascimento nascimento;
    char cpf[15];
    char sexo[2];
} tpCliente;

int validarNome(char *nome){
    //Retirar a quebra de linha da string
    int ln = formatarString(nome);

    if (ln > 20){
        printf("\nVoce digitou um nome de %d caracteres\n"
            "Digite um nome de ate 20 caracteres!\n", ln);
        return 0;
    }else
        return 1;
}

int formatarString(char *string){
    int ln = strlen(string) - 1;
    if ((string[ln]) == '\n')
        string[ln] = '\0';
    return ln;
}

int validarSexo(char *sexo){

    if (
        ((sexo != "M") && (sexo != "m")) && 
        ((sexo != "F") && (sexo != "f")) && 
        ((sexo != "O") && (sexo != "o"))
    ){
        
        printf("Você digitou %s\n", sexo);
        printf("Digite uma opção válida (M, F, O)!\n");
        return 0;
    }else{
        return 1;
    }
}

void cadastrarCliente(tpCliente *c){

    //Inserir nome em loop até que validarNome returne 1
    do{
        printf("Digite o nome do cliente: \n");
        fgets((*c).nome, 40, stdin);
    }while(!validarNome((*c).nome));
    
    printf("Digite a data de nascimento do cliente (dd/mm/aaaa): \n");
    scanf("%d/%d/%d", &(*c).nascimento.dia, &(*c).nascimento.mes, &(*c).nascimento.ano);

    getchar();
    printf("Digite o CPF do cliente: (###.###.###-##): \n");
    fgets((*c).cpf, 15, stdin);
    getchar();

    do{
        printf("Digite o sexo do cliente (F/M): \n");
        fgets((*c).sexo, 2, stdin);
        getchar();
    }while(!validarSexo((*c).sexo));

}

int main(){
//  Variáveis
    tpCliente cliente;

//  Coletar entradas
    cadastrarCliente(&cliente);

//  Exibir saídas
    printf("******DADOS DO CLIENTE******\n");
    printf("Nome:\t\t%s\n", cliente.nome);
    printf("Nascimento:\t%02d/%02d/%d\n", cliente.nascimento.dia,cliente.nascimento.mes,cliente.nascimento.ano);
    printf("CPF:\t\t%s\n", cliente.cpf);
    printf("Sexo:\t\t%c\n", cliente.sexo);

}

