// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LuizFarias20212160056.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>


/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 6;
    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

DataQuebrada quebraData(char data[]){
    DataQuebrada dq;
    char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else 
		dq.valido = 0;
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
    return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: 
    dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. 
    dd e mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

/**
Verifica se é bissexto e altera o valor de ano (soma 2000 se tiver dois dígitos)
Retornos:
    1 se for bissexto;
    0 se não for.
*/
int anoBissexto(int *ano){
    if (*ano <= 99) *ano += 2000;
    if ((*ano % 400) == 0){
        return 1;
    } else if (((*ano % 4) == 0) && ((*ano % 100) != 0)){
        return 1;
    }else{
        return 0;
    }
}

/*
Retornar a quantidade de dias do mes em questão
*/
int diasMes(int mes, int bissexto){
    if (mes <= 7){
        //Se for fevereiro
        if (mes == 2){
            if (bissexto) 
                return 29;
            else 
                return 28;
        }else{
        //Se não for fevereiro e for <= 7, 30 ou 31
            return 30 + (mes % 2);
        }
    }else
        return 31 - (mes % 2);
}

int q1(char data[])
{
    int datavalida = 1;
    DataQuebrada dataQuebrada;
    int i; 
    size_t len;
    int iDia = 0, iMes = 0, iAno = 0;
    int bissexto; //1 se o ano for bissexto, 0 se não for
    int qtdDiasMes;


    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    dataQuebrada = quebraData(data);

    //Verificar se a struct é válida e o intervalo de meses
    if (dataQuebrada.valido == 0) return 0;
    if ((dataQuebrada.iMes < 1) || (dataQuebrada.iMes > 12)) return 0;
    
    bissexto = anoBissexto(&dataQuebrada.iAno); 

    //Definir a quantidade máxima de dias do mês
    qtdDiasMes = diasMes(dataQuebrada.iMes, bissexto);
    
    if (dataQuebrada.iDia < 1 || dataQuebrada.iDia > qtdDiasMes)
        datavalida = 0;

    return datavalida;
}

/*
Função que compara dois numeros: n1 e n2
Retornos:
0 se os dois forem iguais;
1 se o primeiro for maior;
2 se o segundo for maior

Utilizar númros de mesma grandeza (dd, mm ou aaaa)
*/
Compara comparaNumeros(int n1, int n2){
    if (n1 == n2)
        return 0;
    else
        return 2 - (n1 > n2);
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */




DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada datai, dataf;
    Compara comparaAno, comparaDia, comparaMes;
    int bissextoi, bissextof;
    int qtdDiasMesi, qtdDiasMesf;

    if (!q1(datainicial)){
      dma.retorno = 2;

    }else if (!q1(datafinal)){
      dma.retorno = 3;

    }else{


        printf("%s - %s\n", datainicial, datafinal);
        datai = quebraData(datainicial);
        dataf = quebraData(datafinal);

        comparaAno = comparaNumeros(datai.iAno, dataf.iAno);
        comparaMes = comparaNumeros(datai.iMes, dataf.iMes);
        comparaDia = comparaNumeros(datai.iDia, dataf.iDia);
        /* printf(
            "C.Ano: %d\nC.Mes: %d\nC.Dia: %d\n",
            comparaAno,
            comparaMes,
            comparaDia
        ); //debug */

        bissextoi = anoBissexto(&datai.iAno);
        bissextof = anoBissexto(&dataf.iAno);

        qtdDiasMesi = diasMes(datai.iMes, bissextoi);
        qtdDiasMesf = diasMes(dataf.iMes, bissextof);
        
        //Verificar se ano final é maior
        if (comparaAno == I_MAIOR){
            dma.retorno = 4;
            return dma;

        //Verificar se anos são iguais e mes final é maior
        } else if (
            (comparaAno == IGUAIS) && 
            (comparaMes == I_MAIOR)
        ){
            dma.retorno = 4;
            return dma;
        
        //Verificar se ano e mes são iguais e dia final é maior
        }else if(
            (comparaAno == IGUAIS) && 
            (comparaMes == IGUAIS) && 
            (comparaDia == I_MAIOR)
        ){
            dma.retorno = 4;
            return dma;
        }else{

            dma.qtdAnos = dataf.iAno - datai.iAno;
            dma.qtdMeses = dataf.iMes - datai.iMes;
            dma.qtdDias = dataf.iDia - datai.iDia;
            dma.retorno = 1;

            if (dma.qtdDias < 0){
                dma.qtdMeses--;
                dma.qtdDias += qtdDiasMesi;
                if ( 
                    datai.iMes == 2 && 
                    dataf.iMes == 3 && 
                    bissextof
                )
                    dma.qtdDias++; 
            } 
            
            if (dma.qtdMeses < 0){
                dma.qtdAnos--;
                dma.qtdMeses += 12;
            }


            
            /*
            Primeiro, verificar dias. 
                Se dias da data inicial for menor ou igual, qtdDias = diasFinal - diasInicial
                senão, 
                    qtdDias += (qtdDiasMesi - diaInicial) + diaFinal

            depois, verificar meses
                se mes inicialfor menor ou igual, qtdMeses = mesFinal - mesInicial

            */
            /* if (comparaDia == F_MAIOR || comparaDia == IGUAIS){
                dma.qtdDias = dataf.iDia - datai.iDia;
            }else{
                dma.qtdDias = qtdDiasMesi - datai.iDia + dataf.iDia;
            }

            if (comparaAno == IGUAIS){
                if (comparaMes == F_MAIOR){
                    dma.qtdMeses = dataf.iMes - datai.iMes;
                }else{

                }

            }else{

            } */

           

        }
    
        //verifique se a data final não é menor que a data inicial
        //calcule a distancia entre as datas
      //se tudo der certo
    }

    printf(
        "qtdAnos: %d\nqtdMeses: %d\nqtdDias: %d\nRetorno: %d\n",
        dma.qtdAnos,
        dma.qtdMeses,
        dma.qtdDias,
        dma.retorno
    ); //debug
    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}
