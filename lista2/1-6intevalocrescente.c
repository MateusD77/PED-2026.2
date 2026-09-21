/********************
imprimeIntervalo(5,10)
-> chama imprimeIntervalo(6,10)
imprimeIntervalo(6,10)
-> chama imprimeIntervalo(7,10)
imprimeIntervalo(7,10)
-> chama imprimeIntervalo(8,10)
imprimeIntervalo(8,10)
-> chama imprimeIntervalo(9,10)
imprimeIntervalo(9,10)
-> chama imprimeIntervalo(10,10)
imprimeIntervalo(10,10)
-> imprime 10
Retornando:
10,9,8,7,6,5
********************/

#include <stdio.h>

void imprimeIntervalo(int a, int b) {
    if (a == b) {      // caso base
        printf("%d", b);
        return;
    }

    imprimeIntervalo(a + 1, b);

    printf(",%d", a);
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    imprimeIntervalo(a, b);

    return 0;
}
