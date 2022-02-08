#include "OperacoesMatriz.h"

void  imprimeMatriz(int tam, int** matriz){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            printf("matriz[%d][%d] = %d\n",i,j,matriz[i][j]);
        }
    }
}

void preencheMatriz(int linha,int coluna,int valor, int** matriz){
    matriz[linha][coluna] = valor;
    matriz[coluna][linha] = valor;
}

int** criamatriz(int N){
    int **matriz;
    matriz = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        matriz[i] = (int *)calloc(N, sizeof(int));
    }
    return matriz;
}