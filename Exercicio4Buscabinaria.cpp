#include <stdio.h>
#include<stdlib.h>

void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    int vetor[10];
    int valor, comparacoes = 0;
    int inicio = 0, fim = 9, meio, posicao = -1;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    bubble_sort(vetor, 10);

    scanf("%d", &valor);

    while (inicio <= fim) {
        comparacoes++;
        meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor) {
            posicao = meio;
            break;
        }

        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d do vetor ordenado.\n", valor, posicao);
    } else {
        printf("Valor %d nao encontrado.\n", valor);
    }
    printf("Total de comparacoes: %d\n", comparacoes);

    return 0;
}