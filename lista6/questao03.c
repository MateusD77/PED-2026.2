
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} Fila;

Fila *fila_criar(int capacidade) {
    Fila *f = malloc(sizeof(Fila));

    if (f == NULL)
        return NULL;

    f->dados = malloc(capacidade * sizeof(int));

    if (f->dados == NULL) {
        free(f);
        return NULL;
    }

    f->capacidade = capacidade;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;

    return f;
}

int fila_vazia(Fila *f) {
    return f->tamanho == 0;
}

int fila_enqueue(Fila *f, int valor) {
    if (f->tamanho == f->capacidade)
        return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;

    return 1;
}

int fila_dequeue(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        exit(1);
    }

    int valor = f->dados[f->inicio];

    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;

    return valor;
}

void fila_liberar(Fila *f) {
    free(f->dados);
    free(f);
}

int main(void) {
    int N, K;

    printf("Quantidade de criancas (N): ");

    if (scanf("%d", &N) != 1 || N < 1) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    printf("Valor de K: ");

    if (scanf("%d", &K) != 1 || K < 1) {
        printf("Valor de K invalido.\n");
        return 1;
    }

    Fila *f = fila_criar(N);

    if (f == NULL) {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    // Insere as criancas de 1 ate N.
    for (int i = 1; i <= N; i++)
        fila_enqueue(f, i);

    printf("\nOrdem de eliminacao: ");

    while (f->tamanho > 1) {
        // Passa a batata por K - 1 criancas.
        for (int i = 1; i < K; i++) {
            int crianca = fila_dequeue(f);
            fila_enqueue(f, crianca);
        }

        // Elimina a proxima crianca.
        int eliminada = fila_dequeue(f);
        printf("%d ", eliminada);
    }

    int vencedora = fila_dequeue(f);

    printf("\nCrianca vencedora: %d\n", vencedora);

    fila_liberar(f);

    return 0;
}
