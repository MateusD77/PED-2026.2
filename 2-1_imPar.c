#include <stdio.h>
#include <math.h>

int main()
{
    int n, result;
    printf("Digite um valor: ");
    scanf("%d", &n);
    
    result = n%2;
    if (result == 1) {
        printf("O valor %d é Impar", n);
    }
    else {
        printf("O valor %d é Par", n);
    }
    
}