#include <stdio.h>
#include <math.h>

int main()
{
    float n1, n2, result;
    char sinal;
    
    printf("Escolha um numero: ");
    scanf("%f", &n1);
    printf("\nSinal do calculo: ");
    scanf(" %c", &sinal);
    printf("\nEscolha o segundo numero: ");
    scanf("%f", &n2);
    
    if (sinal == '+'){
        result = n1 + n2;
        printf("%.2f + %.2f = %.2f", n1, n2, result);
    }
    else if (sinal == '-'){
        result = n1 - n2;
        printf("%.2f - %.2f = %.2f", n1, n2, result);
    }
    else if (sinal == '*'){
        result = n1 * n2;
        printf("%.2f * %.2f = %.2f", n1, n2, result);
    }
    else if (sinal == '/'){
        result = n1 / n2;
            if (n2 == 0){
                printf("Inpossivel de dividir");
            
            }
            else{
                printf("%.2f / %.2f = %.2f", n1, n2, result);
            }
    }
    return 0;
}
