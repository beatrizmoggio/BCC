#include <stdio.h>

int main(){
    int a, b, c;

    printf("A: ");
    scanf("%d", &a);
    
    printf("B: ");
    scanf("%d", &b);
    
    printf("C: ");
    scanf("%d", &c);

    float mediaSimples = (a + b + c) / 3;
    float mediaPonderada = (a * 0.1) + (b * 0.5) + (c * 0.4);

    printf("Média simples: %.2f\n", mediaSimples);
    printf("Média ponderada: %.2f\n", mediaPonderada);

    printf("\n");
    return 0;
}