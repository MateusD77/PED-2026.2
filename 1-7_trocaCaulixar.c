#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    
    printf("escolha o valor de A: ");
    scanf("%d", &a);
    printf("\nescolha o valor de B: ");
    scanf("%d", &b);
    c = a;
    a = b;
    b = c;
    
    printf("A: %d\nB: %d", a, b);
}