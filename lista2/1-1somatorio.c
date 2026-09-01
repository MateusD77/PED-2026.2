/********************
retornando ao somatorio(n) = 28 
28
27 + (2 - 1)
25 + (3 - 1)
22 + (4 - 1)
18 + (5 - 1)
13 + (6 - 1)
somatorio = 7 + (7 - 1)
n = 7
******************/

#include <stdio.h>

int somatorio(int n) {
    if (n == 1) {      // caso base
        return 1;
    }

    return n + somatorio(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", somatorio(n));

    return 0;
}
