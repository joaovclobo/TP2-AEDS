#include "Removercidades.h"

int CalcularTamanhoPetala(int *petala){
    int i = 1; /*i = 1 para pular o primeiro zero*/
    while (petala[i] != 0){
        i++;
    }
    return i + 1; /*i + 1 para adicionar o ultimo zero */
}

int ContidoVetor(int Cidade, int *Petala){
    int output = 0, i = 0;

    while (Petala[i] != -1)
    {
        if (Petala[i] == Cidade){
            output = 1;
            break;
        }
        i++;
    }
    return output;
}

void RemoveCidades(int** vetorCidades, int* petalaAtual, int totalCidades){
    int i = 0, contaNovovetor = 0;
    int *novoVetor;

    novoVetor = (int*) calloc(totalCidades, sizeof(int));

    while ((*vetorCidades)[i] != -1)
    {
        if (!ContidoVetor((*vetorCidades)[i], petalaAtual))
        {
            novoVetor[contaNovovetor] = (*vetorCidades)[i];
            contaNovovetor++;
        }
        i++;
    }
    novoVetor[contaNovovetor] = -1;

    for (int j = 0; j <= contaNovovetor; j++)
    {
        (*vetorCidades)[j] = novoVetor[j];
    }
}

int CalcularTamanhoVetorCidade(int* Vetor_N){
    int i = 0;
    while(Vetor_N[i] != -1){
        i++;
    }
    return i + 1;
}