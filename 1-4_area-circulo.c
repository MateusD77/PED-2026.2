#include <stdio.h>
#include <math.h>

int main() {
    float raio, area;
    printf("Qual é o raio do Circulo?\n");
    scanf("%f", &raio);
    area = M_PI * pow(raio, 2);
    printf("\nA área do círculo é de %.2f", area);
}
