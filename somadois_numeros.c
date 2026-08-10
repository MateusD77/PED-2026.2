#include <stdio.h>

int main() {
    
    int n1, n2;
    printf("Escolha um número: ");
    scanf("%d", &n1);
    printf("\nEscolha outro número: ");
    scanf("%d", &n2);
    int solucao = n1 + n2;
    printf("\n%d",solucao);
}