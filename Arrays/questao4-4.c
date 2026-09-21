#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char palavra[100];
    char *palavraDinamica;

    /* Lê uma palavra do usuário */
    printf("Digite uma palavra: ");
    scanf("%99s", palavra);

    /* Aloca exatamente o espaço necessário
       (+1 para o caractere '\0') */
    palavraDinamica = (char *) malloc((strlen(palavra) + 1) * sizeof(char));

    if (palavraDinamica == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    /* Copia a palavra para a área alocada dinamicamente */
    strcpy(palavraDinamica, palavra);

    /* Exibe o conteúdo armazenado */
    printf("Palavra original: %s\n", palavra);
    printf("Palavra dinamica: %s\n", palavraDinamica);

    /* Libera a memória alocada */
    free(palavraDinamica);

    return 0;
}
