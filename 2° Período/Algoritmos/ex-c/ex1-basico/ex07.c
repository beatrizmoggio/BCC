#include <stdio.h>

int main(){
    int a, b, c;
    float pesoA, pesoB, pesoC;

    printf("A: ");
    scanf("%d", &a);
    
    printf("B: ");
    scanf("%d", &b);
    
    printf("C: ");
    scanf("%d", &c);

    printf("Peso A: ");
    scanf("%f", &pesoA);
    
    printf("Peso B: ");
    scanf("%f", &pesoB);
    
    printf("Peso C: ");
    scanf("%f", &pesoC);

    float mediaSimples = (a + b + c) / 3;
    float mediaPonderada = (a * pesoA) + (b * pesoB) + (c * pesoC);

    printf("Média simples: %.2f\n", mediaSimples);
    printf("Média ponderada: %.2f\n", mediaPonderada);

    printf("\n");
    return 0;
}