#include "geraPetala.h"
#include "lerarquivo.h"
#include "operacoesMatriz.h"

int main()
{
    char nomeArquivo[50] = "teste10.txt";

    int *totalCidadesptr, *capacidadeCaminhaoPtr,  **matrizDistancias;
    int totalCidades, capacidadeCaminhao;
    int listadeDemandas[1000];
    
    totalCidadesptr = &totalCidades;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, totalCidadesptr, capacidadeCaminhaoPtr, listadeDemandas);

    int *cidadesNpermutadas, j = 1;

    cidadesNpermutadas = (int*) malloc(totalCidades*sizeof(int));

    for (int i = 1; i < totalCidades; i++){
        cidadesNpermutadas[i-1] = i;
    }
    cidadesNpermutadas[totalCidades-1] = -1;

    while (cidadesNpermutadas[j - 1] != -1)
    {
        geraPetala(j, cidadesNpermutadas, capacidadeCaminhao, listadeDemandas, matrizDistancias);
        j++;
    }        

}