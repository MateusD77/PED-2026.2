#include <stdio.h>
#include <math.h>

int main()
{
    int ano;
    printf("digite o ano: ");
    scanf("%d", &ano);
    
    if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0){
        printf("O ano %d é Bissexto", ano);
    }
    else{
        printf("Não é Ano Bissexto");
    }
    return 0;
}
