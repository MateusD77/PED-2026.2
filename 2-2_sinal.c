#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Informe um número: ");
    scanf("%d", &n);
    
    if (n > 0 ){
        printf("Número Positivo");
    }
    else if (n == 0){
        printf("Valor igual a Zero");
    }
    else{
        printf("Número Negativo");
    }
    
}