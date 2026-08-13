#include <stdio.h>
#include <math.h>

int main()
{
    int idade;
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    if (idade <= 11){
        printf("Você é uma CRIANÇA!!!!");
    }
    else if (idade <= 17){
        printf("Olha olha temos um aborecente!!!");
    }
    else if (idade <= 59){
        printf("um Adulto... Bem-Vindo a vida de CLT.");
    }
    else {
        printf("Falta pouco para a posentadoria, Parabéns!");
    }
}