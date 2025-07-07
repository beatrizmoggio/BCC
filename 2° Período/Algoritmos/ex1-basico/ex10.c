#include <stdio.h>

int main() {
    float num;
    int parteInteira;
    float parteDecimal;

    printf("Digite um número real (float): ");
    scanf("%f", &num);

    printf("Número com 2 casas decimais: %.2f\n", num);

    parteInteira = (int)num;
    parteDecimal = num - parteInteira;

    printf("Parte inteira: %d\n", parteInteira);
    printf("Parte decimal: %.6f\n", parteDecimal);
    printf("Notação científica: %.6e\n", num);

    printf("\n");
    return 0;
}
