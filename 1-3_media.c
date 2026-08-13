#include <stdio.h>
#include <math.h>

int main() {
    float n1, n2, n3, media;
    printf("\nPrimeira Nota: ");
    scanf("%f", &n1);
    printf("\nSegunda Nota: ");
    scanf("%f", &n2);
    printf("\nTerceira Nota: ");
    scanf("%f", &n3);
    media = (n1+n2+n3)/3;
    printf("Valor da Média do Aluno: %.2f", media);
}
