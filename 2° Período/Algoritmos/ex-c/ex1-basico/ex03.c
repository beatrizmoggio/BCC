#include <stdio.h>

int main(){
    float larg, comp;

    printf("Qual a largura? ");
    scanf("%f", &larg);

    printf("Qual o comprimento? ");
    scanf("%f", &comp);

    float perimetro = 2*larg + 2*comp;
    float area = larg*comp;

    printf("Perímetro: %.2f\n", perimetro);
    printf("Área:%.2f\n", area);

    printf("\n");
    return 0;
}