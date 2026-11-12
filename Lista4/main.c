#include <stdio.h>
#include "vetor.h"

static void info(const char *titulo, Vetor *v) {
    printf("%s\n  ", titulo);
    show(v);
    printf("  alocado = %d | ocupado = %d\n\n", v->tamanho_alocado, v->tamanho_ocupado);
}

int main() {
    Vetor v = criar_vetor(2);
    info("Vetor recem-criado (capacidade 2):", &v);

    for (int i = 1; i <= 5; i++) {
        append(&v, i * 10);
        printf("append(%d) -> alocado = %d, ocupado = %d\n", i * 10,
               v.tamanho_alocado, v.tamanho_ocupado);
    }
    printf("\n");
    info("Apos 5 appends (cresceu 2 -> 4 -> 8):", &v);

    Vetor s = slice(&v, 1, 3);
    info("slice(v, 1, 3):", &s);

    pop(&v);
    info("Apos pop(v):", &v);

    pop(&v);
    pop(&v);
    info("Apos mais 2 pops (memoria alocada nao diminui):", &v);

    // Casos de erro
    Vetor invalido = slice(&v, 2, 10);
    pop(&s); pop(&s); pop(&s); pop(&s);

    liberar_vetor(&v);
    liberar_vetor(&s);
    liberar_vetor(&invalido);
    return 0;
}
