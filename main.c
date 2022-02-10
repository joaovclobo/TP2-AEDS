#include "geraPetala.h"
#include "lerarquivo.h"
#include "operacoesMatriz.h"
#include "Removercidades.h"

int main()
{
    char nomeArquivo[50] = "teste10.txt";

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
    
    Tamanho_Vetor_Cidade = totalCidades - 1;
    MatrizdePetalas = criamatriz(Qtdcaminhoes, 100);

    for (int i = 0; i < Qtdcaminhoes; i++){
        while (cidadesNaoPerm[j - 1] != -1)
        {
            geraPetala(j, cidadesNaoPerm, capacidadeCaminhao, listadeDemandas, matrizDistancias, &menorRota, &petala1);
            j++;
        }
        menorRota = 0;
        j = 0;      
        
        cidadesNaoPerm = RemoveCidades(cidadesNaoPerm, MatrizdePetalas[i], Tamanho_Vetor_Cidade, CalcularTamanhoPetala(MatrizdePetalas[i]));     
        Tamanho_Vetor_Cidade = CalcularTamanhoVetorCidade(cidadesNaoPerm);
    }
}