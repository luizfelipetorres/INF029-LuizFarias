// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include <stdio.h>
#include <string.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.h
#include "LuizFarias20212160056.h"

void testSomar();    //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{
    

    testQ6();
    /*
    testQ1();
    testQ2();
    testQ3();
    testQ4();
    testQ5();
    testSomar();
    testFatorial();
    */
}

void testSomar()
{
    printf("%d\n", somar(3, 4) == 7);
    printf("%d\n", somar(-1, -3) == -4);
    printf("%d\n", somar(-6, 6) == 0);
    printf("%d\n", somar(74, 9) == 83);
    printf("%d\n", somar(30, -9) == 21);
    printf("%d\n", somar(-2, 8) == 6);

}

void testFatorial()
{
    printf("%d\n", fatorial(3) == 6);
    printf("%d\n", fatorial(1) == 1);
    printf("%d\n", fatorial(5) == 120);
}

void testQ1()
{
    char str[11];
    strcpy(str, "29/02/2015");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "29/02/2012");
    printf("%d\n", q1(str) == 1);
    strcpy(str, "9/13/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "45/4/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "/9/2014");
    printf("%d\n", q1(str) == 0);
    strcpy(str, "1/1/14");
    printf("%d\n", q1(str) == 1);
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int teste = 0;
    DiasMesesAnos dma;

    //teste 1
    printf("\n\nteste %d\n", ++teste);
    
    qtdDias = qtdMeses = qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    
    qtdDias = qtdMeses = qtdAnos = -1;

    printf("\n\nteste %d\n", ++teste);

    strcpy(datainicial, "01/30/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 2);

    //Teste 3
    printf("\n\nteste %d\n", ++teste);

    strcpy(datainicial, "01/3/2015");
    strcpy(datafinal, "40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 3);

    //Teste 4
    printf("\n\nteste %d\n", ++teste);

    strcpy(datainicial, "01/06/2016");
    strcpy(datafinal, "01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 4);

    qtdDias = qtdMeses = qtdAnos = -1;

    //teste 5
    printf("\n\nteste %d\n", ++teste);

    strcpy(datainicial, "06/06/2017");
    strcpy(datafinal, "07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 1);
    printf("%d\n", dma.qtdMeses == 1);
    printf("%d\n", dma.qtdAnos == 0);

    //teste 6
    printf("\nTESTES TABELA");
    char datasi[][11] = {"06/06/2017\0", "06/06/2017\0", "26/07/2017\0", "26/06/2017\0", "27/02/2016\0", 
        "27/02/2015\0", "28/01/2016\0", "28/02/2016\0", "29/02/2016\0", "29/02/2016\0", "29/02/2016\0", 
        "29/02/2016\0"};
    char datasf[][11] = {"07/07/2017\0", "05/07/2018\0", "25/08/2017\0", "26/07/2017\0", "03/03/2017\0", 
        "03/03/2016\0", "29/02/2016\0", "28/02/2017\0", "28/02/2017\0", "28/02/2020\0", "29/02/2020\0", 
        "28/02/2019\0"};
    
    int anos[] = {0, 1, 0, 0, 1, 1, 0, 1, 1, 3, 4, 3};
    int meses[] = {1, 0, 0, 1, 0, 0, 1, 0, 0, 11, 0, 0};
    int dias [] = {1, 29, 30, 0, 4, 5, 1, 0, 0, 30, 0, 0};
    int i;
    for (i = 0; i < 12; i++){
        printf("\n\nteste tabela %d\n", i+1);
        strcpy(datainicial, datasi[i]);
        strcpy(datafinal, datasf[i]);
        dma = q2(datainicial, datafinal);
        printf("%d\n", dma.retorno == 1);
        printf("%d\n", dma.qtdDias == dias[i]);
        printf("%d\n", dma.qtdMeses == meses[i]);
        printf("%d\n", dma.qtdAnos == anos[i]);
    }

    
}

void testQ3()
{
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", q3(str, 'a', 0) == 3);
    printf("%d\n", q3(str, 'b', 0) == 0);
    printf("%d\n", q3(str, 'l', 1) == 0);
    printf("%d\n", q3(str, 'l', 0) == 1);
    printf("%d\n", q3(str, 'L', 0) == 1);
}

void testQ4()
{
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    int teste = 0;

    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    printf("Teste %d\n", ++teste);
    strcpy(strTexto, "Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca, "rato");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n", posicoes[0] == 5);
    printf("%d\n", posicoes[1] == 8);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 37);

    printf("Teste %d\n", ++teste);
    for (i = 0; i < 30; i++)
    {
        posicoes[i] = -1;
    }
    strcpy(strTexto, "Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca, "mui");
    printf("%d\n", q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n", posicoes[0] == 16);
    printf("%d\n", posicoes[1] == 18);
    printf("%d\n", posicoes[2] == 34);
    printf("%d\n", posicoes[3] == 36);
    printf("%d\n", posicoes[4] == 52);
    printf("%d\n", posicoes[5] == 54);
}

void testQ5()
{
    printf("%d\n", q5(345) == 543);
    printf("%d\n", q5(78) == 87);
    printf("%d\n", q5(3) == 3);
    printf("%d\n", q5(5430) == 345);
    printf("%d\n", q5(68944) == 44986);
    printf("%d\n", q5(6894432) == 2344986);
    printf("%d\n", q5(10) == 1);
}

void testQ6()
{
    printf("%d\n", q6(34567368, 3) == 2);
    printf("%d\n", q6(34567368, 4576) == 0);
    printf("%d\n", q6(3539343, 3) == 4);
    printf("%d\n", q6(3539343, 39) == 1);
    printf("%d\n", q6(22222, 22) == 2);
}
