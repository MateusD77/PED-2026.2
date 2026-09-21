#include <stdio.h>

/* Função que copia apenas os números positivos para o vetor resultado.
   Retorna a quantidade de elementos positivos encontrados. */
int filtra_positivos(int vetor[], int tamanho, int resultado[]) {
    int i, j = 0;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > 0) {
            resultado[j] = vetor[i];
            j++;
        }
    }

    return j;
}

int main() {
    int vetor[] = {-10, 25, 0, 48, -3, 7, -50, 12, 99, -1};
    int resultado[10];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int qtdPositivos;
    int i;

    qtdPositivos = filtra_positivos(vetor, tamanho, resultado);

    printf("Vetor original:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n\nVetor com apenas os positivos:\n");
    for (i = 0; i < qtdPositivos; i++) {
        printf("%d ", resultado[i]);
    }

    printf("\n");

    return 0;
}
