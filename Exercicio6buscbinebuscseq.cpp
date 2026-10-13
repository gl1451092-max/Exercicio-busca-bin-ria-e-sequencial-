#include <stdio.h>
#include <stdlib.h>

#define N 1000


int busca_sequencial(int v[], int n, int alvo, int *comparacoes)
{
    int i;

    *comparacoes = 0;
    for (i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == alvo) {
            return i;
        }
    }
    return -1;
}


int busca_binaria(int v[], int n, int alvo, int *comparacoes)
{
    int esq = 0;
    int dir = n - 1;
    int meio;

    *comparacoes = 0;
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        (*comparacoes)++;
        if (v[meio] == alvo) {
            return meio;
        } else if (v[meio] < alvo) {
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}

int main(void)
{
    int vetor[N];
    int i;
    int cs, cb;
    double log2n;
    const char *nomes[3];
    int alvos[3];

   
    for (i = 0; i < N; i++) {
        vetor[i] = i;
    }

    nomes[0] = "Primeiro elemento (0)";
    nomes[1] = "Ultimo elemento (999)";
    nomes[2] = "Valor ausente (1000)";
    alvos[0] = vetor[0];
    alvos[1] = vetor[N - 1];
    alvos[2] = 1000;

    printf("%-24s%12s%10s\n", "Caso", "Sequencial", "Binaria");
    printf("----------------------------------------------\n");
    for (i = 0; i < 3; i++) {
        busca_sequencial(vetor, N, alvos[i], &cs);
        busca_binaria(vetor, N, alvos[i], &cb);
        printf("%-24s%12d%10d\n", nomes[i], cs, cb);
    }

  

    printf("\n");
    printf("n                = %d\n", N);
    printf("log2(n)          = %.2f\n", log2n);
    printf("piso(log2 n) + 1 = %d (max. teorico da binaria)\n",
           (int)log2n + 1);

    return 0;
}