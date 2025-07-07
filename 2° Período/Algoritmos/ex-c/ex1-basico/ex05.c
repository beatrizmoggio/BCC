#include <stdio.h>

int main(){
    float raio;
    const float pi = 3.141593;

    printf("Qual o raio? ");
    scanf("%f", &raio);

    float diametro = 2*raio;
    float circunferencia = 2*pi*raio;
    float area = pi*(raio*raio);

    printf("Diâmetro: %.2f\n", diametro);
    printf("Circunferência: %.2f\n", circunferencia);
    printf("Área: %.2f\n", area);

    printf("\n");
    return 0;
}