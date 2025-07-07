#include <stdio.h>

int main(){
    int a, b;

    printf("Digite um número inteiro (A): ");
    scanf("%d", &a);

    printf("Digite outro número inteiro (B): ");
    scanf("%d", &b);

    int mult = a * b;
    int divInt = a / b;
    float divFloat = (float)a / b;

    printf("Multiplicação: %d\n", mult);
    printf("Divisão Inteira: %d\n", divInt);
    printf("Divisão Float: %.2f\n", divFloat);

    printf("\n");
    return 0;
}