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
    int *cidadesNaoPerm;
    int Tamanho_Vetor_Cidade, menorRota = 0, Qtdcaminhoes = 0, j = 1, T;
    int *petala1;
    int **MatrizdePetalas;
    
    totalCidadesptr = &totalCidades;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, totalCidadesptr, capacidadeCaminhaoPtr, listadeDemandas);

    cidadesNaoPerm = (int*) malloc(totalCidades*sizeof(int));
    petala1 = (int*) calloc((totalCidades*2)+1, sizeof(int));

     for (int i = 0; i < totalCidades; i++){
        Qtdcaminhoes += listadeDemandas[i];
    }
    Qtdcaminhoes /= capacidadeCaminhao;

    for (int i = 1; i < totalCidades; i++){
        cidadesNaoPerm[i-1] = i;
    }
    cidadesNaoPerm[totalCidades-1] = -1;
    
    Tamanho_Vetor_Cidade = totalCidades;
    MatrizdePetalas = criamatriz(Qtdcaminhoes, 100);

    printf("Primeiras Cidade:\n");
    for (j = 0; j < Tamanho_Vetor_Cidade; j++)
        {
            printf("%d ", cidadesNaoPerm[j]);
    }


    for (int i = 0; i < Qtdcaminhoes; i++){
        while (cidadesNaoPerm[j - 1] != -1)
        {
            geraPetala(j, cidadesNaoPerm, capacidadeCaminhao, listadeDemandas, matrizDistancias, &menorRota, &MatrizdePetalas[i]);
            j++;
        }
        menorRota = 0;
        j = 0;      

        cidadesNaoPerm = RemoveCidades(cidadesNaoPerm, MatrizdePetalas[i], Tamanho_Vetor_Cidade, CalcularTamanhoPetala(MatrizdePetalas[i]));     
        Tamanho_Vetor_Cidade = CalcularTamanhoVetorCidade(cidadesNaoPerm);

        printf("\nCidades restantes:\n");

        for (j = 0; j < Tamanho_Vetor_Cidade; j++)
        {
            printf("%d ", cidadesNaoPerm[j]);
        }

    }

    printf("\nCidades restantes ERRADAS:\n");

    for (j = 0; j < Tamanho_Vetor_Cidade; j++)
    {
        printf("%d ", cidadesNaoPerm[j]);
    }
    for (int i = 0; i < Qtdcaminhoes ;i++){
        for (int j = 0; j < CalcularTamanhoPetala(MatrizdePetalas[i]);j++){
            printf("%d ", MatrizdePetalas[i][j]);
        }
        putchar('\n');
    }

    clock_t tempo_final = clock();
    double tempo_diferenca = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %lf segundos\n\n",tempo_diferenca);

}