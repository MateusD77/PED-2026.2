/********************
seq(1) -> return 1
seq(2) -> return 3 * seq(1)
        -> 3 * 1 = 3
seq(3) -> return 3 * seq(2)
        -> 3 * 3 = 9
seq(4) -> return 3 * seq(3)
        -> 3 * 9 = 27
seq(5) -> return 3 * seq(4)
        -> 3 * 27 = 81
seq(6) -> return 3 * seq(5)
        -> 3 * 81 = 243
********************/

#include <stdio.h>

int seq(int n) {
    if (n == 1) {      // caso base
        return 1;
    }

    return 3 * seq(n - 1);
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%d\n", seq(n));

    return 0;
}
