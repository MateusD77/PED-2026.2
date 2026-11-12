#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;            // valor guardado no nó
    struct No *proximo;   // ponteiro para o próximo nó (NULL no último)
} No;

typedef struct {
    No *cabeca;           // primeiro nó, ou NULL se a lista estiver vazia
    int tamanho;          // quantidade de nós
} Lista;

// Cria uma lista vazia
Lista criar_lista(void);

// Operações pedidas no exercício
// insert, acessar e remover devolvem 1 em caso de sucesso e 0 se a posição
// for inválida (ou se faltar memória), sem derrubar o programa.
int insert(Lista *l, int pos, int valor);
void show(Lista *l);
int acessar(Lista *l, int pos, int *valor);
int remover(Lista *l, int pos);
void liberar(Lista *l);

#endif
