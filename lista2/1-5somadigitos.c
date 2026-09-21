/********************
somaDigitos(9) -> return 9
somaDigitos(98)
-> return 8 + somaDigitos(9)
-> 8 + 9 = 17
somaDigitos(987)
-> return 7 + somaDigitos(98)
-> 7 + 17 = 24
somaDigitos(9876)
-> return 6 + somaDigitos(987)
-> 6 + 24 = 30
somaDigitos(98765)
-> return 5 + somaDigitos(9876)
-> 5 + 30 = 35
somaDigitos(987654)
-> return 4 + somaDigitos(98765)
-> 4 + 35 = 39
********************/

#include <stdio.h>

int somaDigitos(int n) {
    if (n < 10) {      // caso base
        return n;
    }

    return (n % 10) + somaDigitos(n / 10);
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", somaDigitos(n));

    return 0;
}
