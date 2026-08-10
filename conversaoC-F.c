#include <stdio.h>
#include <math.h>

int main() {
    float f;
    int c;
    printf("Valor para Cº: ");
    scanf("%d", &c);
    f = ((float)c * 9.0/5.0)+ 32;
    printf("\n Converter %dCº para Fº %.2f", c, f);
}