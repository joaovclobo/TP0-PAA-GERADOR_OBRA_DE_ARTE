/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

     Universidade Federal De Viçosa - Campus Florestal
     Trabalho prático 0 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS

       Professor responsável:
           Daniel Mendes Barbosa

       Aluno responsável:
           João Lobo - 4693

----------------------------------------------------------------------------------------------------------------------------------------------------------- */

#include "funcoesAuxiliares.h"

void printMatrizChar(int linhas, int colunas, char quadro[lin][col]){

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            
            printf("%c", quadro[i][j]);
        }

        putchar('\n');
    }
}

void criaQuadroVazio(char quadro[lin][col]){

    char quadroI[lin][lin];

    for (int i = 0; i < lin; i++){

        for (int j = 0; j < col; j++){

            if(i == 0 || i == lin-1){
                quadro[i][j] = '-';
                
            } 
            else if (j == 0 || j == col-1){
                quadro[i][j] = '|';

            } else{
                quadro[i][j] = ' ';

            }
        }
    }
}

int normalizaNumero(int numeroUsuario){
    
    if (numeroUsuario <= 0 ){
        return (rand() % 100 + 1);

    } if (numeroUsuario > 100 ){
        return 100;

    } else {
        return numeroUsuario;

    }
}

void preencheAsteriscoSimples(int numeroFiguras, char quadro[lin][col]){

    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        preencheAsteriscoSimplesI(numeroFiguras, quadro, linha, coluna, preenchido);
 
    }
}

void preencheAsteriscoSimplesI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido){
        
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

void preencheSomaAsteriscos(int numeroFiguras, char quadro[lin][col]){

    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        preencheSomaAsteriscosI(numeroFiguras, quadro, linha, coluna, preenchido);
 
    }
}

void preencheSomaAsteriscosI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido){
        
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

void preencheXAsteriscos(int numeroFiguras, char quadro[lin][col]){

    int linha; int coluna;
    int preenchido = false;

    for (int i = 0; i < numeroFiguras; i++){

        preencheXAsteriscosI(numeroFiguras, quadro, linha, coluna, preenchido);

    }
}

void preencheXAsteriscosI(int numeroFiguras, char quadro[lin][col], int linha, int coluna, int preenchido){
        
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

void preencheFigsAleatorias(int numeroFiguras, char quadro[lin][col]){
        
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

void preencheRetasFibonacci(char quadro[lin][col]){
    
    int i = 0, preenchido = false, numSorteado;

    char barraInv = '\\', barra = '/', barraVert = '|', undeline = '_', traco = '-', igual = '=';
    char retaSorteada;
    char* retas = "\\/|_";
    
    int linha = sequenciaFibonacci(i) / 80;
    int coluna = sequenciaFibonacci(i) % 80;


    while (linha <= lin && coluna <= col) {
        numSorteado = rand() % 4;
        retaSorteada = retas[numSorteado];

        quadro[linha][coluna] = retaSorteada;
        
        linha = (sequenciaFibonacci(i) / 80) + 1;
        coluna = (sequenciaFibonacci(i) % 80) + 1;
        i++;
        
    }
}

void preencheRetasI(char quadro[lin][col], int linha, int coluna){
      
    char barraInv = '\\', barra = '/', barraVert = '|', undeline = '_', traco = '-', igual = '=';
    char* retas = "\\/|_-=";
    
    int numSorteado = rand() % 6;

    char retaSorteada = retas[numSorteado];
    
    quadro[linha][coluna] = retaSorteada;
}

int sequenciaFibonacci(int poss){
    
    int n1 = 0, n2 = 1;
    int n3 = n1 + n2;

    if (poss <= 0 ){

        return n1;

    } else if (poss == 1){
        
        return n2;

    }else {
        for (int i = 3; i <= poss; i++) {

            n1 = n2;
            n2 = n3;
            n3 = n1 + n2;
        }
    }

    return n3;
}

int geraLinhaAleatoria(){
    return (rand() % 18 + 1);

}

int geraColunaAleatoria(){
    return (rand() % 78 + 1);

}

int verificaVazio(int linha, int coluna, char quadro[lin][col]){
    
    if (quadro[linha][coluna] != ' '){
        return false;

    } else{
        return true;

    }
}
