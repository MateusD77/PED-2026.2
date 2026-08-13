#include <stdio.h>
#include <math.h>

int main()
{
    float quilo, distan, valor;
    int pessoas;
    
    printf("Calculo de Viagem - Giselda\n\n");
    
    printf("Quantos Quilometros seu carro faz por Litro: ");
    scanf("%f", &quilo);
    printf("\n\nQual a Distancia que será percorrida: ");
    scanf("%f", &distan);
    printf("\n\nQual o valor do Combustivel: ");
    scanf("%f", &valor);
    printf("\n\nQuantas Pessoas irão?");
    scanf("%d", &pessoas);
    quilo = distan/quilo; //litros
    printf("\nLitros: %.2f", quilo);
    valor = valor * quilo;
    printf("\nValor total: %2.f", valor);
    valor = valor/pessoas; // valor que cada pessoa deverá gastar
    printf("\n\nO total divido para %d é de:\nR$%.2f", pessoas, valor);
}