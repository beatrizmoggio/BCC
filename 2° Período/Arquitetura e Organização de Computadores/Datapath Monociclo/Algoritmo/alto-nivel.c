#include <stdio.h>

int main(){
    int a = 2;
    int b = 7;
    int result = 0;
    int soma = 0;
    int i = a + 1;


    // Estrutura Condicional (beq) = 10 pontos
    if (a == b){
        result = a + b;
        printf("\nO resultado quando (a == b): %d + %d = %d\n", a, b, result);
    } else {
        result = a - b;
        printf("\nO resultado quando (a != b): %d - %d = %d\n", a, b, result);
    }
    

    // Estrutura Condicional (slt) = 10 pontos
    if (a < b){
        result = a + a;
        printf("\nO resultado quando (a > b): %d + %d = %d\n", a, a, result);
    }
    else{
        result = b + b;
        printf("\nO resultado quando (b > a): %d + %d = %d\n", b, b, result);
    }
    

    // Laço de Repetição Não-Aninhado (while com slt) = 12 pontos
    while (i < b){
        soma = soma + i;
        i = i + 1;
    }

    for(i; i > a; i--){
        soma = soma - i;
    }
    printf("\nA soma dos números entre %d e %d = %d\n", a, b, soma);


    int mem[5] = {0};
    mem[2] = a;
    b = mem[2];

    for (int i = 0; i < 5; i++){
        printf("%d ", mem[i]);
    }

    return 0;
}