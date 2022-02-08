#include "lerarquivo.h"
#include "operacoesMatriz.h"

int main(){
    char nomeArquivo[50] = "teste10.txt";
    int *Nptr, *capacidadeCaminhaoPtr,  **matrizDistancias, N, capacidadeCaminhao, listadeDemandas[1000];
    Nptr = &N;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, Nptr, capacidadeCaminhaoPtr, listadeDemandas);

    printf("%d\n%d\n", N, capacidadeCaminhao);

    for (int i = 0; i < N; ++i) {
        printf("%d ", listadeDemandas[i]);
    }

    printf("\n");

    imprimeMatriz(N, matrizDistancias);

}