#include "Removercidades.h"

int CalcularTamanhoPetala(int *petala){
    int i = 1; /*i = 1 para pular o primeiro zero*/
    while (petala[i] != 0){
        i++;
    }
    return i + 1; /*i + 1 para adicionar o ultimo zero */
}

int ContidoVetor(int Cidade, int *Petala, int TamanhoPetala){
    int output = 0;
    for (int i = 1; i < TamanhoPetala - 1; i++){ /* i = -1 e Tamanho Petala -1 é para que não precise checar os valores da petala que são 0*/
        if (Petala[i] == Cidade){
            printf("%d %d", Cidade, Petala[i]);
            output = 1;
            break;
        }
    }
    return output;
}

int* RemoveCidades(int *Vetor_cidades,int *petala_atual, int Tamanho_Vetor_Cidade,int TamanhoPetala){
    int *NovoVetor, IndiceNovoVetor = 0;
    NovoVetor = (int* ) calloc(Tamanho_Vetor_Cidade - TamanhoPetala + 3, sizeof(int)); /* Novo vetor terá o tamanho do Vetor Cidade diminuido das cidades presente na petala que não são 0 como 0 aparece duas vezes temos que somar 2*/
    for (int IndiceVetorCidade = 0; IndiceVetorCidade < Tamanho_Vetor_Cidade; IndiceVetorCidade++){
        if (!(ContidoVetor(Vetor_cidades[IndiceVetorCidade], petala_atual, TamanhoPetala))){
            NovoVetor[IndiceNovoVetor] = Vetor_cidades[IndiceVetorCidade];
            IndiceNovoVetor++; 
        } 
    }
    NovoVetor[Tamanho_Vetor_Cidade - 1] = -1;
    free(Vetor_cidades);
    return NovoVetor;
}

int CalcularTamanhoVetorCidade(int* Vetor_N){
    int i = 0;
    while(Vetor_N[i] != -1){
        i++;
    }
    return i + 1;
}