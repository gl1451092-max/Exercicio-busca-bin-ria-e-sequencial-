#include <stdio.h>
#include <stdlib.h>

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

int busca_binaria_recursiva(int v[], int inicio, int fim, int valor, int *chamadas) {
    (*chamadas)++;

    if (inicio > fim) {
        return -1;
    }

    int meio = inicio + (fim - inicio) / 2;

    if (v[meio] == valor) {
        return meio;
    }

    if (v[meio] < valor) {
        return busca_binaria_recursiva(v, meio + 1, fim, valor, chamadas);
    } else {
        return busca_binaria_recursiva(v, inicio, meio - 1, valor, chamadas);
    }
}

int main() {
    int vetor[10];
    int valor, chamadas = 0;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    bubble_sort(vetor, 10);

    scanf("%d", &valor);

    int pos = busca_binaria_recursiva(vetor, 0, 9, valor, &chamadas);

    if (pos != -1) {
        printf("Valor %d encontrado na posicao %d do vetor ordenado.\n", valor, pos);
    } else {
        printf("Valor %d nao encontrado.\n", valor);
    }
    printf("Total de chamadas recursivas: %d\n", chamadas);

    return 0;
}