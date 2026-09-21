/********************
contaDigitos(9)      -> return 1
contaDigitos(98)     -> return 1 + contaDigitos(9)
                      -> 1 + 1 = 2
contaDigitos(987)    -> return 1 + contaDigitos(98)
                      -> 1 + 2 = 3
contaDigitos(9876)   -> return 1 + contaDigitos(987)
                      -> 1 + 3 = 4
contaDigitos(98765)  -> return 1 + contaDigitos(9876)
                      -> 1 + 4 = 5
contaDigitos(987654) -> return 1 + contaDigitos(98765)
                      -> 1 + 5 = 6
********************/

#include <stdio.h>

int contaDigitos(int n) {
    if (n < 10) {      // caso base
        return 1;
    }

    return 1 + contaDigitos(n / 10);
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", contaDigitos(n));

    return 0;
}
