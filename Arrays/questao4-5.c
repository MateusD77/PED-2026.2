#include <stdio.h>
#include <stdlib.h>

void adiciona_valor(int **v, int *tamanho, int valor, int pos) {
    int i;

    /* Se a posição estiver fora do tamanho atual,
       aumenta o vetor com realloc */
    if (pos >= *tamanho) {
        *v = realloc(*v, (pos + 1) * sizeof(int));

        if (*v == NULL) {
            printf("Erro na realocacao de memoria!\n");
            exit(1);
        }

        /* Inicializa as novas posições com 0 */
        for (i = *tamanho; i <= pos; i++) {
            (*v)[i] = 0;
        }

        *tamanho = pos + 1;
    }

    /* Adiciona o valor na posição desejada */
    (*v)[pos] = valor;
}

int main() {
    int tamanho = 5;
    int i;

    int *v = malloc(tamanho * sizeof(int));

    if (v == NULL) {
        printf("Erro na alocacao de memoria!\n");
        return 1;
    }

    /* Inicializa o vetor */
    for (i = 0; i < tamanho; i++) {
        v[i] = i + 1;
    }

    /* Adiciona um valor em uma posição além do tamanho atual */
    adiciona_valor(&v, &tamanho, 99, 7);

    printf("Vetor:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");

    free(v);

    return 0;
}
