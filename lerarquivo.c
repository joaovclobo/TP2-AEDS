#include "lerarquivo.h"

int** lerarquivo(char nomeArquivo[20], int *ponteiroQuantCidades, int *capacidadeCaminhao, int *listaDemandas){
    FILE *ponteiroArquivo;
    char auxdistancias[10], temp[10], demandas[500]="";
    int  **ponteiroMatriz, linha, coluna, valor;
    ponteiroArquivo = fopen(nomeArquivo, "r");
    if (ponteiroArquivo != NULL){
        fscanf(ponteiroArquivo, "%d", ponteiroQuantCidades);
        ponteiroMatriz = criamatriz(*ponteiroQuantCidades, *ponteiroQuantCidades);
        fscanf(ponteiroArquivo, "%d", capacidadeCaminhao);
        fgets(demandas, 10, ponteiroArquivo);
        fgets(demandas, 1000, ponteiroArquivo);
        for (int i = 0; i < *ponteiroQuantCidades; i++){
            if (i == 0){
                strcpy(temp, (strtok(demandas, " ")));
            }
            else{
                strcpy(temp, (strtok(NULL, " ")));
            }
            *(listaDemandas + i) = atoi(temp);
        }    
        for (int i = 0; i < *ponteiroQuantCidades * *ponteiroQuantCidades; i++){
            fgets(auxdistancias, 20, ponteiroArquivo);
            if (auxdistancias[1] == '\000'){
                break;
            }
            linha = atoi(strtok(auxdistancias, " "));
            coluna = atoi(strtok(NULL, " "));
            valor = atoi(strtok(NULL, " "));
            preencheMatriz(linha, coluna, valor, ponteiroMatriz);
        }
        fclose(ponteiroArquivo);
        return ponteiroMatriz;
    }
    else {
        printf("Erro arquivo não encontrado\n");
        return NULL;
    }
}
        
        

