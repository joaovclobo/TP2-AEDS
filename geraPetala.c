#include "geraPetala.h"

/* Vetor de elementos. Coloque quantos elementos
 * quiser, mas o ultimo deve ser sempre NULL. */

int* geraPetala(int r, int* vetor, int capacidadeCaminhao, int* listadeDemandas, int** matrizDistancias)                                
{
    int menor_rota = 0;
    int *vetor_aux, *petala = NULL;
    int *num;
    int n;
    int i, j;

    n = 0;

    while (vetor[n] != -1)
        n++;

    if (r > n)
    {
        printf("Nao faz sentido r > n.\n");
        return NULL;
    }
    
    num = (int *)calloc(r + 1, sizeof(int));
    vetor_aux = (int *)calloc(r, sizeof(int));

    if (num == NULL)
    {
        perror("malloc");
        return NULL;
    }

    if (vetor_aux == NULL)
    {
        perror("malloc");
        return NULL;
    }

    while (num[r] == 0)
    {
        for (i = 0; i < n; i++)
        {

            if (confereRepeticao(num, r))
            {
                for (j = 0; j < r; j++)
                {
                    // printf("%d ", vetor[num[j]]);
                    vetor_aux[j] = vetor[num[j]];
                }

                // for (j = 0; j < r; j++)
                // {
                //         printf("%d", vetor_aux[j]);
                // }
                // putchar('\n');

                if (calcdemandas(vetor_aux, listadeDemandas, r, capacidadeCaminhao))
                {
                    // printf("Demanda ok - ");
                    // for (j = 0; j < r; j++)
                    // {
                    //     printf("%d ", vetor_aux[j]);
                    // }

                    if (menor_rota == 0)
                    {
                        menor_rota = calcrota(vetor_aux, matrizDistancias, r);
                        // printf("\nDistancia rota: %d", calcrota(vetor_aux, matrizDistancias, r));
                    } else if (calcrota(vetor_aux, matrizDistancias, r) < menor_rota)
                    {
                        menor_rota = calcrota(vetor_aux, matrizDistancias, r);
                        petala = vetor_aux;
                        // printf("\nDistancia rota: %d", calcrota(vetor_aux, matrizDistancias, r));
                    }
                    // putchar('\n');
                }
            }

            num[0]++;
        }

        for (i = 0; i < r; i++)
        {
            if (num[i] == n)
            {
                num[i] = 0;
                num[i + 1]++;
            }
        }
    }
    // printf("\n%d", menor_rota);
    free(num);
    printf("%d", menor_rota);
    return petala;
}

char confereRepeticao(int *num, int r)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r && i != j; j++)
        {
            if (num[i] == num[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int calcdemandas(int *petalapossivel, int *demandas, int r, int Demanda_Caminhao)
{
    int Total = 0;
    for (int i = 0; i < r; i++)
    {
        Total += demandas[petalapossivel[i]];
    }
    if (Total == Demanda_Caminhao)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int calcrota(int *petalapossivel, int **matrizDistancias, int r)
{
    int Total = 0, j = 0;

    while(j < r){

        if (j == 0)
        {
            Total += matrizDistancias[0][petalapossivel[j]];
        }

        if (j == r-1){
            Total += matrizDistancias[petalapossivel[r-1]][0];
            break;
        } 
        
        if (j != 0 || j != r-1){
            Total += matrizDistancias[petalapossivel[j]][petalapossivel[j+1]];
            j++;
        }
    }

    return Total;
}