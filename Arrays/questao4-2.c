#include <stdio.h>
#include <stdlib.h>

void func(int *var1, int *var2){
    int aux;
    
    if (*var1 < *var2){
        aux = *var1;
        *var1 = *var2;
        *var2 = aux;
    }
}

int main()
{
    int var1, var2;
    scanf("%d\n", &var1);
    scanf("%d", &var2);
    
    func(&var1, &var2);
    
    printf("Primeira variavel é MAIOR %d\n", var1);
    printf("Segunda variavel é MENOR %d", var2);
    return 0;
}
