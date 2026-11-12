#ifndef VETOR_H
#define VETOR_H

typedef struct {
    int *dados;            // ponteiro para o primeiro elemento do array dinâmico
    int tamanho_alocado;   // quantas posições foram reservadas na memória
    int tamanho_ocupado;   // quantas posições estão realmente em uso
} Vetor;

// Funções auxiliares (criação e liberação de memória)
Vetor criar_vetor(int capacidade_inicial);
void liberar_vetor(Vetor *v);

// Operações pedidas no exercício
void append(Vetor *v, int valor);
void show(Vetor *v);
Vetor slice(Vetor *v, int x0, int x1);
void pop(Vetor *v);

#endif
