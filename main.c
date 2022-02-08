#include "geraPetala.h"
#include "lerarquivo.h"
#include "operacoesMatriz.h"

int main()
{
    char nomeArquivo[50] = "teste3.txt";

    int *totalCidadesptr, *capacidadeCaminhaoPtr,  **matrizDistancias;
    int totalCidades, capacidadeCaminhao;
    int listadeDemandas[1000];
    int *cidadesNaoPerm, j = 1;
    int *petala1 = NULL;
    
    totalCidadesptr = &totalCidades;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, totalCidadesptr, capacidadeCaminhaoPtr, listadeDemandas);

    cidadesNaoPerm = (int*) malloc(totalCidades*sizeof(int));
    // petala1 = (int*) calloc(totalCidades, sizeof(int)); // avaliar dps

    for (int i = 1; i < totalCidades; i++){
        cidadesNaoPerm[i-1] = i;
    }
    cidadesNaoPerm[totalCidades-1] = -1;

    while (cidadesNaoPerm[j - 1] != -1)

    {
        petala1 = geraPetala(j, cidadesNaoPerm, capacidadeCaminhao, listadeDemandas, matrizDistancias);
        j++;
    }
}