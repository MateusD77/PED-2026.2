#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    
    printf("Informe o lado A: ");
    scanf("%f", &a);
    printf("\nInforme o lado B: ");
    scanf("%f", &b);
    printf("\nInforme o lado C: ");
    scanf("%f", &c);
    
    if (a+b <= c || a+c <= b || c+b <= a){
        printf("\nNão forma um triangulo");
    }
    else if (a == b && b == c){
        printf("\nÉ um triangulo Equilatero");
    }
    else if (a == b || a == c || b == c){
        printf("\nÉ um triangulo Isosceles");
    }
    else {
        printf("\nEscaleno");
    }
}