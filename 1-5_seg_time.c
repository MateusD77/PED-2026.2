#include <stdio.h>
#include <math.h>

int main() {
    int total_seg, seg, min, hor;
    printf("Digite a quantidade de segundos: ");
    scanf("%d", &total_seg);
    hor = total_seg / 3600;
    min = (total_seg % 3600) / 60;
    seg = total_seg % 60;
    printf("\nConvertendo os %d em horas!!\n", total_seg);
    printf("\n%d:%d:%d",hor,min,seg);
}
