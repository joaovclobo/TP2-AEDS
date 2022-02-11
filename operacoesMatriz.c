#include "operacoesMatriz.h"

void  imprimeMatriz(int linha, int coluna, int** matriz){
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("matriz[%d][%d] = %d\n",i,j,matriz[i][j]);
        }
    }
}

void preencheMatriz(int linha,int coluna,int valor, int** matriz){
    matriz[linha][coluna] = valor;
    matriz[coluna][linha] = valor;
}

int** criamatriz(int linha, int coluna){
    int **matriz;
    matriz = (int **)calloc(coluna, sizeof(int *));
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = (int *)calloc(coluna, sizeof(int));
    }
    return matriz;
}