#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

// Cria um vetor vazio com a capacidade inicial informada (mínimo 1).
Vetor criar_vetor(int capacidade_inicial) {
    Vetor v;
    if (capacidade_inicial < 1) {
        capacidade_inicial = 1;
    }
    v.dados = (int *) malloc(capacidade_inicial * sizeof(int));
    if (v.dados == NULL) {
        printf("Erro: falha ao alocar memoria.\n");
        v.tamanho_alocado = 0;
    } else {
        v.tamanho_alocado = capacidade_inicial;
    }
    v.tamanho_ocupado = 0;
    return v;
}

// Libera a memória do vetor.
void liberar_vetor(Vetor *v) {
    free(v->dados);
    v->dados = NULL;
    v->tamanho_alocado = 0;
    v->tamanho_ocupado = 0;
}

// Adiciona valor ao final. Se estiver cheio, dobra o tamanho alocado.
void append(Vetor *v, int valor) {
    if (v->tamanho_ocupado >= v->tamanho_alocado) {
        int novo_tamanho = (v->tamanho_alocado == 0) ? 1 : v->tamanho_alocado * 2;
        int *novo = (int *) realloc(v->dados, novo_tamanho * sizeof(int));
        if (novo == NULL) {
            printf("Erro: falha ao realocar memoria.\n");
            return;
        }
        v->dados = novo;
        v->tamanho_alocado = novo_tamanho;
    }
    v->dados[v->tamanho_ocupado] = valor;
    v->tamanho_ocupado++;
}

// Imprime apenas os elementos em uso.
void show(Vetor *v) {
    printf("[");
    for (int i = 0; i < v->tamanho_ocupado; i++) {
        printf("%d", v->dados[i]);
        if (i < v->tamanho_ocupado - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Retorna um novo vetor com cópias dos elementos de x0 até x1 (inclusive).
// O novo vetor tem tamanho_alocado exatamente igual à quantidade copiada.
Vetor slice(Vetor *v, int x0, int x1) {
    Vetor novo;
    novo.dados = NULL;
    novo.tamanho_alocado = 0;
    novo.tamanho_ocupado = 0;

    if (x0 < 0 || x1 >= v->tamanho_ocupado || x0 > x1) {
        printf("Erro: intervalo [%d, %d] invalido.\n", x0, x1);
        return novo;
    }

    int qtd = x1 - x0 + 1;
    novo.dados = (int *) malloc(qtd * sizeof(int));
    if (novo.dados == NULL) {
        printf("Erro: falha ao alocar memoria.\n");
        return novo;
    }
    for (int i = 0; i < qtd; i++) {
        novo.dados[i] = v->dados[x0 + i];
    }
    novo.tamanho_alocado = qtd;
    novo.tamanho_ocupado = qtd;
    return novo;
}

// Remove o último elemento (não reduz a memória alocada).
void pop(Vetor *v) {
    if (v->tamanho_ocupado == 0) {
        printf("Erro: vetor vazio, nada para remover.\n");
        return;
    }
    v->tamanho_ocupado--;
}
