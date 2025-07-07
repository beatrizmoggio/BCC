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
    } else {
        result = a - b;
    }
    

    // Estrutura Condicional (slt) = 10 pontos
    if (a < b){
        result = a + a;
    }
    else{
        result = b + b;
    }
    

    // Laço de Repetição Não-Aninhado (while com slt) = 12 pontos
    while (i < b){
        soma = soma + i;
        i = i + 1;
    }

    for(i; i > a; i--){
        soma = soma - i;
    }

    // Memória
    int mem[5] = {0};
    mem[2] = a;
    int b = mem[2];

    return 0;
}