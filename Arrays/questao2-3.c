#include <stdio.h>

int main() {
    int v[10];
    int i;

    /* Preenchendo o vetor com os valores de 1 a 10
       usando apenas aritmética de ponteiros */
    for (i = 0; i < 10; i++) {
        *(v + i) = i + 1;
    }

    /* Imprimindo o vetor usando apenas aritmética de ponteiros */
    printf("Vetor: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", *(v + i));
    }

    printf("\n");

    return 0;
}
