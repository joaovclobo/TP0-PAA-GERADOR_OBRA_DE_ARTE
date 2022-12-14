/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

     Universidade Federal De Viçosa - Campus Florestal
     Trabalho prático 0 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS

       Professor responsável:
           Daniel Mendes Barbosa

       Aluno responsável:
           João Lobo - 4693

----------------------------------------------------------------------------------------------------------------------------------------------------------- */

#include "funcoesQuadro.h"

//Funções da opção 1

void preencheAsteriscoSimples(int numeroFiguras, char quadro[LIN][COL]){

    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        preencheAsteriscoSimplesI(numeroFiguras, quadro, linha, coluna, preenchido);
 
    }
}

void preencheAsteriscoSimplesI(int numeroFiguras, char quadro[LIN][COL], int linha, int coluna, int preenchido){
        
    linha = geraLinhaAleatoria();
    coluna = geraColunaAleatoria();
    preenchido = false;
    
    while (!preenchido){

        if (verificaVazio(linha, coluna, quadro)){
            
            quadro[linha][coluna] = '*';
            preenchido = true;

        } else {

            linha = geraLinhaAleatoria();
            coluna = geraColunaAleatoria();

        }
    }
}

//Funções da opção 2

void preencheSomaAsteriscos(int numeroFiguras, char quadro[LIN][COL]){

    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        preencheSomaAsteriscosI(numeroFiguras, quadro, linha, coluna, preenchido);
 
    }
}

void preencheSomaAsteriscosI(int numeroFiguras, char quadro[LIN][COL], int linha, int coluna, int preenchido){
        
    linha = geraLinhaAleatoria();
    coluna = geraColunaAleatoria();
    preenchido = false;
    
    while (!preenchido){

        if (verificaVazio(linha, coluna, quadro) && verificaVazio(linha-1, coluna, quadro) && verificaVazio(linha+1, coluna, quadro) && verificaVazio(linha, coluna-1, quadro) && verificaVazio(linha, coluna+1, quadro)){
            
            quadro[linha][coluna] = '*';

            quadro[linha-1][coluna] = '*';
            quadro[linha+1][coluna] = '*';

            quadro[linha][coluna-1] = '*';
            quadro[linha][coluna+1] = '*';

            preenchido = true;

        } else {

            linha = geraLinhaAleatoria();
            coluna = geraColunaAleatoria();

        }
    }
}

//Funções da opção 3

void preencheXAsteriscos(int numeroFiguras, char quadro[LIN][COL]){

    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        preencheXAsteriscosI(numeroFiguras, quadro, linha, coluna, preenchido);

    }
}

void preencheXAsteriscosI(int numeroFiguras, char quadro[LIN][COL], int linha, int coluna, int preenchido){
        
    linha = geraLinhaAleatoria();
    coluna = geraColunaAleatoria();
    preenchido = false;
    
    while (!preenchido){

        if (verificaVazio(linha, coluna, quadro) && verificaVazio(linha-1, coluna-1, quadro) && verificaVazio(linha-1, coluna+1, quadro) && verificaVazio(linha+1, coluna-1, quadro) && verificaVazio(linha+1, coluna+1, quadro)){
            
            quadro[linha][coluna] = '*';

            quadro[linha-1][coluna-1] = '*';
            quadro[linha-1][coluna+1] = '*';

            quadro[linha+1][coluna-1] = '*';
            quadro[linha+1][coluna+1] = '*';

            preenchido = true;

        } else {

            linha = geraLinhaAleatoria();
            coluna = geraColunaAleatoria();

        }
    }
}

//Função da opção 4

void preencheFigsAleatorias(int numeroFiguras, char quadro[LIN][COL]){
        
    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        int tipoFigura  = rand() % 3;

        if (tipoFigura == 0) {
            
            preencheAsteriscoSimplesI(numeroFiguras, quadro, linha, coluna, preenchido);

        } else if (tipoFigura == 1) {

            preencheSomaAsteriscosI(numeroFiguras, quadro, linha, coluna, preenchido);

        } else {
            
            preencheXAsteriscosI(numeroFiguras, quadro, linha, coluna, preenchido);            

        }
    }
}

//Funções da opção 5 - Fibonacci e série harmonica

void preencheRetasFibonacci(char quadro[LIN][COL]){
    
    int i = 0, numSorteado;
    int numChars;
    int linha = 1;
    int coluna = sequenciaFibonacci(i) % 80;

    char* retas = "\\/|_";
    char* formasPlanas = "[-]_/|\\";
    char* curvos = "()Oo.";
    char* letras = "XLVTIMNZHWY";
    char seqCharsSorteada[50];

    int numSort2 = rand() % 4;

    switch (numSort2) {
        case 0:;
            strcpy(seqCharsSorteada, retas);
            numChars = 4;
            break;

        case 1:;
            strcpy(seqCharsSorteada, formasPlanas);
            numChars = 7;
            break;

        case 2:;
            strcpy(seqCharsSorteada, curvos);
            numChars = 5;
            break;

        case 3:;
            strcpy(seqCharsSorteada, letras);
            numChars = 11;
            break;

        default:
            break;
    }    

 
    while (linha < LIN && coluna <= COL) {
        
        numSorteado = rand() % numChars;

        quadro[linha][coluna + 1] = seqCharsSorteada[numSorteado];
        
        linha =  serieHarmonica(i) * 4;
        coluna = sequenciaFibonacci(i) % 80;
        
        i++;
    }
}

//Funções da opção 5 - Snake

void preencheComidas(char quadro[LIN][COL]){

    int linha; int coluna;
    int preenchido = false;
    int numeroFiguras = rand() % 37;

    for (int i = 0; i < numeroFiguras; i++){

        preencheComidasI(numeroFiguras, quadro, linha, coluna, preenchido);

    }
}

void preencheComidasI(int numeroFiguras, char quadro[LIN][COL], int linha, int coluna, int preenchido){
        
    linha = geraLinhaAleatoria();
    coluna = geraColunaAleatoria();
    preenchido = false;
    
    while (!preenchido){

        if (verificaVazio(linha, coluna, quadro)){
            
            quadro[linha][coluna] = 'O';
            preenchido = true;

        } else {

            linha = geraLinhaAleatoria();
            coluna = geraColunaAleatoria();

        }
    }
}

void percorreSnakeZigZag(char quadro[LIN][COL]){
    
    int alternaZigZag = true;
    char aux;

    for (int i = 1; i < LIN-1; i++){

        if (alternaZigZag){

            if (comidaNaLinha(i, quadro)){

                // caminhaEsqDir(i, 1, COL-1, quadro);

                for (int j = 1; j < COL-1; j++){
        
                    aux = quadro[i][j]; 
                    quadro[i][j] = '>';
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);
                    
                    quadro[i][j] = substituiSnake(aux, false);
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);

                }

                
                alternaZigZag = false;

            } else{

                aux = quadro[i][1];
                quadro[i][1] = 'V';
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);
                
                quadro[i][1] = substituiSnake(aux, true);
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);
            }

        } else{

            if (comidaNaLinha(i, quadro)){

                // caminhaDirEsq(i, COL-2, 1, quadro);

                for (int j = COL-2; j >= 1; j--){
        
                    aux = quadro[i][j]; 
                    quadro[i][j] = '<';
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);
                    
                    quadro[i][j] = substituiSnake(aux, false);
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);
                }

                alternaZigZag = true;

            } else{
                
                aux = quadro[i][COL-2];
                quadro[i][COL-2] = 'V';
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);
                
                quadro[i][COL-2] = substituiSnake(aux, true);
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);

            }
        }
    }
}

void percorreSnakeEspiral(char quadro[LIN][COL]){
    
    int m = LIN, n = COL;
    int i, k = 0, l = 0;
    int mAux, nAux;
    int caminhoVazio = true;    
    char aux;
 
    while (k < m && l < n) {
        
        
        for (i = l; i < n; ++i) {
        
        if (k != 0){

            aux = quadro[k][i]; 
                quadro[k][i] = '>';
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);
                
                quadro[k][i] = substituiSnake(aux, false);
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);
            
            }
        }
        k++;

        for (i = k; i < m; ++i) {
            
            if (n-1 != COL-1){
            
                aux = quadro[i][n-1];
                quadro[i][n-1] = 'V';
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);
                
                quadro[i][n-1] = substituiSnake(aux, true);
                printMatrizChar(LIN, COL, quadro);
                usleep(12500);

            }
        }
        n--;


        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                
                if (m-1 != LIN-1){
                
                    aux = quadro[m - 1][i]; 
                    quadro[m - 1][i] = '<';
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);
                    
                    quadro[m - 1][i] = substituiSnake(aux, false);
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);
                }

            }
            m--;
        }

        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                
                if (l != 0){
                
                    aux = quadro[i][l]; 
                    quadro[i][l] = 'A';
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);
                    
                    quadro[i][l] = substituiSnake(aux, true);
                    printMatrizChar(LIN, COL, quadro);
                    usleep(12500);

                }
            }
            l++;
        }
    }
}
