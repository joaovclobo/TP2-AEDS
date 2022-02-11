#include "geraPetala.h"
#include "lerarquivo.h"
#include "operacoesMatriz.h"
#include "Removercidades.h"
#include <time.h>

int main()
{
    putchar('\n');
    char nomeArquivo[50];
    scanf("%s", &nomeArquivo);
    clock_t tempo_inicial = clock();
    
    // char nomeArquivo[50] = "teste-4-cidades.txt";

    int *totalCidadesptr, *capacidadeCaminhaoPtr, **matrizDistancias;
    int totalCidades, capacidadeCaminhao;
    int listadeDemandas[1000];
    int QntdCaminhoes = 0, TamanhoVetorCidade;
    int *cidadesNaoPerm, menorRota = 0, j = 1, k = 0;
    int **MatrizdePetalas;
    int *petala1;
    
    totalCidadesptr = &totalCidades;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, totalCidadesptr, capacidadeCaminhaoPtr, listadeDemandas);

    cidadesNaoPerm = (int*) malloc(totalCidades*sizeof(int));
    petala1 = (int*) calloc(((totalCidades-1)*2)+1, sizeof(int));

    for (int i = 0; i < totalCidades; i++){
        QntdCaminhoes += listadeDemandas[i];
    }
    QntdCaminhoes /= capacidadeCaminhao;

    for (int i = 1; i < totalCidades; i++){
        cidadesNaoPerm[i-1] = i;
    }
    cidadesNaoPerm[totalCidades-1] = -1;

    TamanhoVetorCidade = totalCidades;
    MatrizdePetalas = criamatriz(QntdCaminhoes, ((totalCidades-1)*2)+1);

    for (int i = 0; i < QntdCaminhoes; i++){

        while (cidadesNaoPerm[j - 1] != -1)
        {
            geraPetala(j, cidadesNaoPerm, capacidadeCaminhao, listadeDemandas, matrizDistancias, &menorRota, &petala1);
            j++;
        }

        while (petala1[k] != -1)
        {
            MatrizdePetalas[i][k] = petala1[k];
            k++;
        }
        MatrizdePetalas[i][k] = -1;
        menorRota = 0;
        j = 0;
        k = 0;      

        RemoveCidades(&cidadesNaoPerm, petala1, totalCidades);  
    }
    
    printf("\n");
    for (int i = 0; i < QntdCaminhoes ;i++){
        j = 0;
        while (MatrizdePetalas[i][j] != -1){
            printf("%d ", MatrizdePetalas[i][j]);
            j++;
        }
        putchar('\n');
    }

    printf("\nCidades nao atendiadas:\n");
    j = 0;
    while (cidadesNaoPerm[j] != -1)
    {
        printf("%d ", cidadesNaoPerm[j]);
        j++;
    }
    printf("\n\n");

    clock_t tempo_final = clock();
    double tempo_diferenca = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %lf segundos\n\n",tempo_diferenca);
}