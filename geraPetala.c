#include "geraPetala.h"

/* Vetor de elementos. Coloque quantos elementos
 * quiser, mas o ultimo deve ser sempre NULL. */

int geraPetala(int r, int* vetor, int capacidadeCaminhao, int* listadeDemandas, int** matrizDistancias)                                
{

    /* vetor que representara cada permutacao. */
    int *num;
    /* quantidade de elementos do vetor. */
    int n;
    /* tamanho de cada permutacao. */
    /* controle de loop. */
    int i, j;
    /* Obtem a quantidade de elementos do vetor. */
    int *vetor_aux;
    n = 0;
    while (vetor[n] != -1)
        n++;

    if (r > n)
    {
        printf("Nao faz sentido r > n.\n");
        return -1;
    }
    /* Aloca espaco para o vetor num. Lembre-se
     * que o vetor `num' representa um numero
     * na base n com r algarismos. */
    num = (int *)calloc(r + 1, sizeof(int));
    vetor_aux = (int *)calloc(r + 1, sizeof(int));

    if (num == NULL)
    {
        perror("malloc");
        return -1;
    }

    if (vetor_aux == NULL)
    {
        perror("malloc");
        return -1;
    }

    /* Inicio do algoritmo. */
    while (num[r] == 0)
    {
        for (i = 0; i < n; i++)
        {
            /* Mostra a permutacao na tela se
             * e somente se `num' nao contem
             * algarismos repetidos. */
            if (confereRepeticao(num, r))
            {
                for (j = 0; j < r; j++)
                {
                    // printf("%d ", vetor[num[j]]);
                    vetor_aux[j] = vetor[num[j]];
                }
                // putchar('\n');
                if (calcdemandas(vetor_aux, listadeDemandas, r, capacidadeCaminhao))
                {
                    printf("Demanda OK! - ");
                    for (j = 0; j < r; j++)
                    {
                        printf("%d ", vetor_aux[j]);
                    }
                    printf(" - Distancia rota: %d", calcrota(vetor_aux, matrizDistancias, r));
                    putchar('\n');
                }
            }
            /* incrementa o algarismo menos
             * significativo. */
            num[0]++;
        }
        /* distribui os vai-uns. */
        for (i = 0; i < r; i++)
        {
            if (num[i] == n)
            {
                num[i] = 0;
                num[i + 1]++;
            }
        }
    }
    free(num);
    return 0;
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

int calcrota(int *petalapossivel, int **matriz_distancias, int r)
{
    int Total = 0;
    for (int i = 0; i < r; i++)
    {
        if (i == 0)
        {
            Total += matriz_distancias[0][petalapossivel[0]];
        } else if (i==r-1){
            Total += matriz_distancias[petalapossivel[r-1]][0];
        }
        Total += matriz_distancias[petalapossivel[i]][petalapossivel[i+1]];
    }
    return Total;
}
