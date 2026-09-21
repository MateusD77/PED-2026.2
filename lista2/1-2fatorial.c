#include <stdio.h>

/********************
fatorial(1) -> return 1
fatorial(2) -> return 2 * fatorial(1) = 2 * 1
fatorial(3) -> return 3 * fatorial(2) = 3 * 2
fatorial(4) -> return 4 * fatorial(3) = 4 * 6
fatorial(5) -> return 5 * fatorial(4) = 5 * 24
fatorial(6) -> return 6 * fatorial(5) = 6 * 120
fatorial(7) -> return 7 * fatorial(6) = 7 * 720
********************/

long long fatorial(int n) {
    if (n == 1) {      // caso base
        return 1;
    }

    return n * fatorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%lld\n", fatorial(n));

    return 0;
}
