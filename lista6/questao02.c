
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *dados;
    int tamanho_alocado;
    int topo;
} Pilha;

Pilha *pilha_criar(int capacidade) {
    Pilha *p = malloc(sizeof(Pilha));

    if (p == NULL)
        return NULL;

    p->dados = malloc(capacidade * sizeof(char));

    if (p->dados == NULL) {
        free(p);
        return NULL;
    }

    p->tamanho_alocado = capacidade;
    p->topo = 0;

    return p;
}

int pilha_vazia(Pilha *p) {
    return p->topo == 0;
}

void pilha_push(Pilha *p, char valor) {
    if (p->topo == p->tamanho_alocado) {
        int nova_capacidade = p->tamanho_alocado * 2;
        char *novo = realloc(
            p->dados,
            nova_capacidade * sizeof(char)
        );

        if (novo == NULL) {
            printf("Erro de memoria.\n");
            exit(1);
        }

        p->dados = novo;
        p->tamanho_alocado = nova_capacidade;
    }

    p->dados[p->topo] = valor;
    p->topo++;
}

char pilha_pop(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        exit(1);
    }

    p->topo--;
    return p->dados[p->topo];
}

void pilha_liberar(Pilha *p) {
    free(p->dados);
    free(p);
}

int abertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

int fechamento(char c) {
    return c == ')' || c == ']' || c == '}';
}

int combina(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

int balanceada(char expressao[]) {
    Pilha *p = pilha_criar(strlen(expressao) + 1);

    if (p == NULL) {
        printf("Erro ao criar a pilha.\n");
        exit(1);
    }

    int correta = 1;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (abertura(c)) {
            pilha_push(p, c);
        }
        else if (fechamento(c)) {
            if (pilha_vazia(p)) {
                correta = 0;
                break;
            }

            char topo = pilha_pop(p);

            if (!combina(topo, c)) {
                correta = 0;
                break;
            }
        }
    }

    if (!pilha_vazia(p))
        correta = 0;

    pilha_liberar(p);

    return correta;
}

int main(void) {
    char expressao[1000];

    printf("Digite uma expressao: ");

    if (fgets(expressao, sizeof(expressao), stdin) == NULL)
        return 1;

    if (balanceada(expressao))
        printf("Expressao balanceada.\n");
    else
        printf("Expressao nao balanceada.\n");

    return 0;
}
