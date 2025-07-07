#include <stdio.h>

int main(){
    int a, b;

    printf("Digite um número inteiro (A): ");
    scanf("%d", &a);

    printf("Digite outro número inteiro (B): ");
    scanf("%d", &b);
    
    int soma = a + b;
    int sub = a - b;

    printf("Soma: %d\n", soma);
    printf("Subtração: %d\n", sub);

    printf("\n");
    return 0;
}