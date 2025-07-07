#include <stdio.h>

int main(){
    float graus, rad;
    const float pi = 3.141593;

    printf("Valor em graus: ");
    scanf("%f", &graus);

    rad = graus * (pi/180);
    printf("%.2f graus é %.6f radianos.\n", graus, rad);

    printf("\n");
    return 0;
}