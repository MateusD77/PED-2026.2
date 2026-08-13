#include <stdio.h>
#include <math.h>

int main()
{
    int n1, n2, n3;
    printf("Escolha o Primeiro N°: ");
    scanf("%d", &n1);
    printf("\nEscolha o Primeiro N°: ");
    scanf("%d", &n2);
    printf("\nEscolha o Primeiro N°: ");
    scanf("%d", &n3);
    printf("1°: %d\n2°: %d\n3°: %d", n1, n2, n3);
    if (n1 > n2 && n1 > n3) {
        printf("\nO 1° valor é maior");
    }
    else if (n2 > n1 && n2 > n3){
        printf("\nO 2° valor é maior.");
    }
    else{
        printf("\nO 3° valor é o maior.");
    }
}