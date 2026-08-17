#include <stdio.h>

int main()
{
    int a, b;
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("\nDigite o valor de B: ");
    scanf("%d", &b);
    
    a = b + a;
    b = a - b;
    a = a - b;
    
    printf("\nA: %d\nB: %d", a, b);
}