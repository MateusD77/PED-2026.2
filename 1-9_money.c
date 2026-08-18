#include <stdio.h>
#include <math.h>

int main()
{
    int valor;
    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    printf("Digite um valor: ");
    scanf("%d", &valor);
    printf("\n");
    for (int i = 0; i < 7; i++){
        int quantidade = valor / notas[i];
        valor = valor % notas[i];
        printf("%d notas(s) de R$%d,00\n",quantidade, notas[i]);
    }
    
}