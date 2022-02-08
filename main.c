#include "geraPetala.h"
#include "lerarquivo.h"
#include "operacoesMatriz.h"
#include "Removercidades.h"

int main()
{
    char nomeArquivo[50] = "teste10.txt";

    int *totalCidadesptr, *capacidadeCaminhaoPtr,  **matrizDistancias;
    int totalCidades, capacidadeCaminhao;
    int listadeDemandas[1000];
    int *cidadesNaoPerm, j = 1;
    int Qtdcaminhoes = 0, Tamanho_Vetor_Cidade;
    
    totalCidadesptr = &totalCidades;
    capacidadeCaminhaoPtr = &capacidadeCaminhao;
    matrizDistancias = lerarquivo(nomeArquivo, totalCidadesptr, capacidadeCaminhaoPtr, listadeDemandas);
    
    cidadesNaoPerm = (int*) malloc(totalCidades*sizeof(int));
    for (int i = 0; i < totalCidades; i++){
        Qtdcaminhoes += listadeDemandas[i];
    }
    Qtdcaminhoes /= capacidadeCaminhao;
    for (int i = 1; i < totalCidades; i++){
        cidadesNaoPerm[i-1] = i;
    }
    cidadesNaoPerm[totalCidades-1] = -1;
    Tamanho_Vetor_Cidade = totalCidades - 1;
    for (int i = 0; i < Qtdcaminhoes; i++){
        while (cidadesNaoPerm[j - 1] != -1)
        {
            geraPetala(j, cidadesNaoPerm, capacidadeCaminhao, listadeDemandas, matrizDistancias);
            j++;
        }
        cidadesNaoPerm = RemoveCidades(cidadesNaoPerm, petala_atual, Tamanho_Vetor_Cidade, CalcularTamanhoPetala(petala_atual));     
        Tamanho_Vetor_Cidade = CalcularTamanhoVetorCidade(cidadesNaoPerm);
    }
}