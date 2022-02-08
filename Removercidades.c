#include "Removercidades.h"

int calctampetala(int *petala){
    int i = 1; /*i = 1 para pular o primeiro zero*/
    while (petala[i] != 0){
        i++;
    }
    return i + 1; /*i + 1 para adicionar o ultimo zero */
}

int estanovetor(int Cidade, int *Petala, int TamanhoPetala){
    int out = 0;
    for (int i = 1; i < TamanhoPetala - 1; i++){ /* i = -1 e Tamanho Petala -1 é para que não precise checar os valores da petala que são 0*/
        if (Petala[i] == Cidade){
            out = 1;
            break;
        }
    }
    return out;
}

int* removecidades(int *Vetor_cidades,int *petala_atual, int Tamanho_Vetor_Cidade,int TamanhoPetala){
    int *Vetoraux, j = 0;
    Vetoraux = (int* ) calloc(Tamanho_Vetor_Cidade - TamanhoPetala + 2, sizeof(int));
    for (int n = 0; n < Tamanho_Vetor_Cidade; n++){
        if (!(estanovetor(Vetor_cidades[n], petala_atual, TamanhoPetala))){
            Vetoraux[j] = Vetor_cidades[n];
            j++; 
        }
    }
    return Vetoraux;
}
int CalcTamanhoVetorCidade(int* Vetor_N){
    int i = 0;
    while(Vetor_N[i] != -1){
        i++;
    }
    return i + 1;
}