#include <stdio.h>
#include <string.h>

int formatarString(char *string);

/*
Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. 
Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. 
A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida.
*/

/*

  Validar sexo
  Dado



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
    char sexo;
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

int validarSexo(char sexo){

    if (
      (sexo == 'M') || (sexo == 'm') ||
      (sexo == 'F') || (sexo == 'f') || 
      (sexo == 'O') || (sexo == 'o') 
    ){
        return 1;
        
    }else{
        printf("Digite uma opção válida (M, F, O)!\n");
        return 0;
    }
}

int validarCPF(char *cpf){
  int ln = formatarString(cpf);

  if (
    (ln != 13) || 
    (cpf[3] != '.') ||
    (cpf[7] != '.') ||
    (cpf[11] != '-') 
  ){
    printf("CPF inválido! Digite no formato ###.###.###-##\n");
    return 0;
  }else{
    return 1;
  }
}

int validarNascimento(tpNascimento nascimento){

  if (
    (nascimento.dia < 1) || (nascimento.dia > 31) ||
    (nascimento.mes < 1) || (nascimento.mes > 12) ||
    (nascimento.ano < 1900) || (nascimento.ano > 2022)
  ){
    printf("Data invalida! Digite no formato ##/##/####:\n");
    return 0;
  }
    return 1;
}

void cadastrarCliente(tpCliente *c){

    //Inserir nome em loop até que validarNome returne 1
    do{
        printf("Digite o nome do cliente: \n");
        fgets((*c).nome, 40, stdin);
    }while(!validarNome((*c).nome));
    
    printf("Digite a data de nascimento do cliente (dd/mm/aaaa): \n");

    do{
      scanf("%d/%d/%d", &(*c).nascimento.dia, &(*c).nascimento.mes, &(*c).nascimento.ano);
      getchar();
      
    }while(!validarNascimento((*c).nascimento));

    printf("Digite o CPF do cliente: (###.###.###-##): \n");
    do{    
      fgets((*c).cpf, 15, stdin);
      getchar();
    }while(!validarCPF((*c).cpf));

    printf("Digite o sexo do cliente (F/M/O): \n");
    do{
        scanf("%c", &(*c).sexo);
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
    printf("Nascimento:\t%02d/%02d/%d\n", 
      cliente.nascimento.dia,
      cliente.nascimento.mes,
      cliente.nascimento.ano
    );
    printf("CPF:\t\t%s\n", cliente.cpf);
    printf("Sexo:\t\t%c\n", cliente.sexo);

}

