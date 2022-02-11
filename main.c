#include "geraPetala.h"
#include "lerarquivo.h"
#include "operacoesMatriz.h"
#include "Removercidades.h"
#include <time.h>

int main()
{
    clock_t tempo_inicial = clock();

    char nomeArquivo[50] = "teste-8-cidades.txt";

    int *totalCidadesptr, *capacidadeCaminhaoPtr, **matrizDistancias;
    int totalCidades, capacidadeCaminhao;
    int listadeDemandas[1000];
    int QntdCaminhoes = 0, TamanhoVetorCidade;
    int *cidadesNaoPerm, menorRota = 0, j = 1;
    int *petala1;
    int **MatrizdePetalas;
    
    totalCidadesptr = &totalCidades;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, totalCidadesptr, capacidadeCaminhaoPtr, listadeDemandas);

    cidadesNaoPerm = (int*) malloc(totalCidades*sizeof(int));
    petala1 = (int*) calloc((totalCidades*2)+1, sizeof(int));
    for (int i = 0; i < totalCidades; i++){
        QntdCaminhoes += listadeDemandas[i];
    }
    QntdCaminhoes /= capacidadeCaminhao;
    for (int i = 1; i < totalCidades; i++){
        cidadesNaoPerm[i-1] = i;
    }

     for (int i = 0; i < totalCidades; i++){
        QntdCaminhoes += listadeDemandas[i];
    }
    QntdCaminhoes /= capacidadeCaminhao;

    for (int i = 1; i < totalCidades; i++){
        cidadesNaoPerm[i-1] = i;
    }
    cidadesNaoPerm[totalCidades-1] = -1;
    TamanhoVetorCidade = totalCidades - 1;
    MatrizdePetalas = criamatriz(QntdCaminhoes, 100);
    for (int i = 0; i < QntdCaminhoes; i++){
        while (cidadesNaoPerm[j - 1] != -1)
        {
            geraPetala(j, cidadesNaoPerm, capacidadeCaminhao, listadeDemandas, matrizDistancias, &menorRota, &MatrizdePetalas[i]);
            j++;
        }
        cidadesNaoPerm = RemoveCidades(cidadesNaoPerm, MatrizdePetalas[i], TamanhoVetorCidade, CalcularTamanhoPetala(MatrizdePetalas[i]));
        TamanhoVetorCidade = CalcularTamanhoVetorCidade(cidadesNaoPerm);
        menorRota = 0;
        j = 0;
    }
    for (int i = 0; i < QntdCaminhoes ;i++){
        for (int j = 0; j < CalcularTamanhoPetala(MatrizdePetalas[i]);j++){
            printf("%d ", MatrizdePetalas[i][j]);
        }
        putchar('\n');
    }

    clock_t tempo_final = clock();
    double tempo_diferenca = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %lf segundos\n\n",tempo_diferenca);

}