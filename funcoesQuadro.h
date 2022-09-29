/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

     Universidade Federal De Viçosa - Campus Florestal
     Trabalho prático 0 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS

       Professor responsável:
           Daniel Mendes Barbosa

       Aluno responsável:
           João Lobo - 4693

----------------------------------------------------------------------------------------------------------------------------------------------------------- */

#include "funcoesAuxiliares.h"


//Funções da opção 1

void preencheAsteriscoSimples(int numeroFiguras, char quadro[lin][col]);

void preencheAsteriscoSimplesI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido);


//Funções da opção 2

void preencheSomaAsteriscos(int numeroFiguras, char quadro[lin][col]);

void preencheSomaAsteriscosI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido);


//Funções da opção 3

void preencheXAsteriscos(int numeroFiguras, char quadro[lin][col]);

void preencheXAsteriscosI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido);


//Função da opção 4

void preencheFigsAleatorias(int numeroFiguras, char quadro[lin][col]);


//Funções da opção 5 - Fibonacci e série harmonica

void preencheRetasFibonacci(char quadro[lin][col]);


//Funções da opção 5 - Snake

void preencheComidas(char quadro[lin][col]);

void preencheComidasI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido);

void percorreSnakeZigZag(char quadro[lin][col]);

void percorreSnakeEspiral(int m, int n, char quadro[lin][col]);
