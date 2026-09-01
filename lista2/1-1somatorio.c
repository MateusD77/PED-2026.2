/********************
soma(1) -> return 1
soma(2) -> return 2 + soma(1) = 2 + 1 
soma(3) -> return 3 + soma(2) = 3 + 3
soma(4) -> return 4 + soma(3) = 6 + 4
soma(5) -> return 5 + soma(4) = 10 + 5
soma(6) -> return 6 + soma(5) = 15 + 6
soma(7) -> return 7 + soma(6) = 21 + 7
******************/

#include <stdio.h>

int soma(int n) {
    if (n == 1) {      // caso base
        return 1;
    }

    return n + soma(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", soma(n));

    return 0;
}
