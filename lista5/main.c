#include <stdio.h>
#include "lista.h"

static void estado(const char *titulo, Lista *l) {
    printf("%s\n  ", titulo);
    show(l);
    printf("  tamanho = %d\n\n", l->tamanho);
}

static void tenta_insert(Lista *l, int pos, int valor) {
    if (insert(l, pos, valor)) {
        printf("insert(pos=%d, valor=%d): ok\n", pos, valor);
    } else {
        printf("insert(pos=%d, valor=%d): posicao invalida\n", pos, valor);
    }
}

static void tenta_remover(Lista *l, int pos) {
    if (remover(l, pos)) {
        printf("remover(pos=%d): ok\n", pos);
    } else {
        printf("remover(pos=%d): posicao invalida\n", pos);
    }
}

int main() {
    Lista l = criar_lista();
    estado("Lista vazia:", &l);

    // Inserções: fim (pos == tamanho), inicio, meio e posicoes invalidas
    tenta_insert(&l, 0, 20);   // lista vazia: vira a cabeca
    tenta_insert(&l, 1, 40);   // fim
    tenta_insert(&l, 0, 10);   // inicio
    tenta_insert(&l, 2, 30);   // meio
    tenta_insert(&l, 4, 50);   // fim
    tenta_insert(&l, 9, 99);   // invalida
    tenta_insert(&l, -1, 99);  // invalida
    printf("\n");
    estado("Apos inserções:", &l);

    // Acesso
    int v;
    for (int pos = 0; pos <= 5; pos++) {
        if (acessar(&l, pos, &v)) {
            printf("acessar(%d) = %d\n", pos, v);
        } else {
            printf("acessar(%d): posicao invalida\n", pos);
        }
    }
    printf("\n");

    // Remoções: primeiro, meio e ultimo
    tenta_remover(&l, 0);
    estado("Apos remover o primeiro:", &l);

    tenta_remover(&l, 1);
    estado("Apos remover o do meio (pos 1):", &l);

    tenta_remover(&l, l.tamanho - 1);
    estado("Apos remover o ultimo:", &l);

    tenta_remover(&l, 7);      // invalida
    printf("\n");

    liberar(&l);
    estado("Apos liberar:", &l);
    return 0;
}
