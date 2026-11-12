#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista criar_lista(void) {
    Lista l;
    l.cabeca = NULL;
    l.tamanho = 0;
    return l;
}

// Insere valor de modo que o novo nó passe a ocupar a posição pos.
int insert(Lista *l, int pos, int valor) {
    if (pos < 0 || pos > l->tamanho) {
        return 0;                       // posição inválida
    }

    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;

    if (pos == 0) {
        // vira a nova cabeça (funciona também com lista vazia)
        novo->proximo = l->cabeca;
        l->cabeca = novo;
    } else {
        // caminha até o nó anterior à posição desejada (pos - 1)
        No *anterior = l->cabeca;
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->proximo;
        }
        // ORDEM IMPORTA: primeiro o novo aponta para o resto da lista,
        // só depois o anterior passa a apontar para o novo.
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }

    l->tamanho++;
    return 1;
}

// Percorre os ponteiros até NULL imprimindo cada valor.
void show(Lista *l) {
    No *atual = l->cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Guarda em *valor o elemento da posição pos. Retorna 0 se pos for inválida.
int acessar(Lista *l, int pos, int *valor) {
    if (pos < 0 || pos >= l->tamanho) {
        return 0;
    }
    No *atual = l->cabeca;
    for (int i = 0; i < pos; i++) {
        atual = atual->proximo;         // um salto por posição
    }
    *valor = atual->valor;
    return 1;
}

// Remove o nó da posição pos, redireciona ponteiros e libera a memória.
int remover(Lista *l, int pos) {
    if (pos < 0 || pos >= l->tamanho) {
        return 0;
    }

    No *removido;
    if (pos == 0) {
        removido = l->cabeca;
        l->cabeca = removido->proximo;
    } else {
        No *anterior = l->cabeca;
        for (int i = 0; i < pos - 1; i++) {
            anterior = anterior->proximo;
        }
        removido = anterior->proximo;
        anterior->proximo = removido->proximo;   // pula o removido
    }

    free(removido);
    l->tamanho--;
    return 1;
}

// Libera todos os nós restantes.
void liberar(Lista *l) {
    No *atual = l->cabeca;
    while (atual != NULL) {
        No *proximo = atual->proximo;   // guarda antes de dar free
        free(atual);
        atual = proximo;
    }
    l->cabeca = NULL;
    l->tamanho = 0;
}
