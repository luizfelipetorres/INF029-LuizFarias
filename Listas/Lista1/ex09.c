/* ENUNCIADO

Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. 
Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. 
A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida.
*/

#include <stdio.h>
#include <string.h>

#define MAX_NOME 20

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



int formatarString(char *string);

/**
  Função que verifica se o ano é bissexto
    -Retorna 1 se for bissexto
    -Retorna 0 se não for
*/
int anoBissexto (int ano){
  int bissexto = 0;
  
  if ((ano % 400) == 0) 
    bissexto = 1;
  else if (
    (ano % 100 != 0) && 
    (ano % 4 == 0)
  ){
    bissexto = 1;
  } else
    bissexto = 0;
  return bissexto;
}

/**
  Função que valida o nome do cliente
    -Retorna 0 se tiver até 20 caracteres
    -Retorna o número de caracteres se tiver mais de 20
  */
int validarNome(char *nome){
    //Retirar a quebra de linha da string
    int ln = formatarString(nome);

    if (ln > MAX_NOME){
        return ln;
    }else
        return 0;
}

/**
  Função auxiliar usada para remover a quebra de linha da string
*/
int formatarString(char *string){
    int ln = strlen(string) - 1;
    if ((string[ln]) == '\n')
        string[ln] = '\0';
    return ln;
}

/**
  Função que valida o sexo do cliente
    -Retorna 1 se estiver válido
    -Retorna 0 se estiver inválido
*/
int validarSexo(char sexo){

    if (
      (sexo == 'M') || (sexo == 'm') ||
      (sexo == 'F') || (sexo == 'f') || 
      (sexo == 'O') || (sexo == 'o') 
    ){
        return 1;
        
    }else{
        return 0;
    }
}

/**
  Função que valida o CPF do cliente
    -Retorna 1 se estiver válido
    -Retorna 0 se estiver inválido
*/
int validarCPF(char *cpf){
  int ln = formatarString(cpf);

  if (
    (ln != 13) || 
    (cpf[3] != '.') ||
    (cpf[7] != '.') ||
    (cpf[11] != '-') 
  ){
    return 0;
  }else{
    return 1;
  }
}

/**
  Valida a data de nascimento do cliente
    -Retorna 1 se estiver válido
    -Retorna 0 se estiver inválido
*/
int validarNascimento(tpNascimento nascimento){
  int bissexto = anoBissexto(nascimento.ano);

  if (nascimento.ano < 1900) return 0;
  else if (nascimento.mes < 1 || nascimento.mes > 12) return 0;
  else if (nascimento.dia < 1 || nascimento.dia > 31) return 0;

  if (nascimento.mes == 2){
    if (bissexto && nascimento.dia > 29) return 0;
    else if (!bissexto && nascimento.dia > 28) return 0;
    else 
      return 1;
  }else if (nascimento.mes <=7){
    if (nascimento.mes % 2 == 0 && nascimento.dia == 31)
      return 0;
    else
      return 1;
  }
    else{
      if (nascimento.mes % 2 == 1 && nascimento.dia == 31)
        return 0;
      else
        return 1;
  }    
}


/**
  Função principal, coleta as entradas e chama as validações
*/
void cadastrarCliente(tpCliente *c){
    int validate = 0;

    //Inserir nome em loop até que validarNome returne 1
    do{
        printf("Digite o nome do cliente (20 caracteres): \n");
        fgets((*c).nome, 40, stdin);
        validate = validarNome((*c).nome);
        if (validate)
          printf("\nVoce digitou um nome de %d caracteres\n", validate);
    }while(validate);
    
    do{
      printf("Digite a data de nascimento do cliente (dd/mm/aaaa): \n");
      scanf("%d/%d/%d", &(*c).nascimento.dia, &(*c).nascimento.mes, &(*c).nascimento.ano);
      getchar();
      validate = validarNascimento((*c).nascimento);
      if (!validate) 
        printf("Data invalida!!! ");
    }while(!validate);

    do{    
      printf("Digite o CPF do cliente: (###.###.###-##): \n");
      fgets((*c).cpf, 15, stdin);
      getchar();
      validate = validarCPF((*c).cpf);
      if (!validate) 
        printf("CPF inválido!!! ");
    }while(!validate);

    do{
      printf("Digite o sexo do cliente (F/M/O): \n");
      scanf("%c", &(*c).sexo);
      getchar();
      validate = validarSexo((*c).sexo);
      if (!validate)  
        printf("Opção inválida!!! ");
    }while(!validate);

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

