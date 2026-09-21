/********************
arara
isPalindromo("arara",0,4)
a == a
-> isPalindromo("arara",1,3)
isPalindromo("arara",1,3)
r == r
-> isPalindromo("arara",2,2)
isPalindromo("arara",2,2)
inicio >= fim
return 1
Retornos:
1
1
1
Resultado: 1
arada
isPalindromo("arada",0,4)
a == a
-> isPalindromo("arada",1,3)
isPalindromo("arada",1,3)
r != d
return 0
Resultado: 0
********************/

#include <stdio.h>
#include <string.h>

int isPalindromo(char palavra[], int inicio, int fim) {

    if (inicio >= fim) {     // caso base
        return 1;
    }

    if (palavra[inicio] != palavra[fim]) {
        return 0;
    }

    return isPalindromo(palavra, inicio + 1, fim - 1);
}

int main() {

    char palavra[100];

    scanf("%s", palavra);

    printf("%d\n",
           isPalindromo(
               palavra,
               0,
               strlen(palavra) - 1
           ));

    return 0;
}
