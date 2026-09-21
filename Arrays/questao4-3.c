/******************
Basiamente ao receber o valor x = 5, e o y = 6
Quando chega na função do ponteiro, o ponteiro do x (*xp),
ele é quebrado quando chega no px = py, indicando que o ponteiro de x não existe mais
porque ele também aponta para y, no fim somente o y tem seu valor aumentado.

*******************/
#include <stdio.h>

void func(int *px, int *py) {  
    px = py;
    printf("px = %d, py = %d\n", *px, *py);
    *py = (*py) * (*px);
    printf("px = %d, py = %d\n", *px, *py);  
    *px = *px + 2;
    printf("px = %d, py = %d\n", *px, *py);
} 
int main () { 
      int x, y; 
      scanf("%d", &x);     
      scanf("%d", &y);  
      func(&x, &y); 
      printf("x = %d, y = %d", x, y);
      return 0;
} 
