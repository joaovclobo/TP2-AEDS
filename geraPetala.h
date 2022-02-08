#include <stdlib.h>
#include <stdio.h>

int geraPetala(int r, int* vetor, int capacidadeCaminhao, int* listadeDemandas, int** matrizDistancias);

char confereRepeticao(int *num, int r);

int calcdemandas(int* petalapossivel, int* demandas, int r, int Demanda_Caminhao);

int calcrota(int* petalapossivel, int** matriz_distancias, int r);