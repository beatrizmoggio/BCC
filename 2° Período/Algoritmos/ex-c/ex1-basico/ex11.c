#include <stdio.h>

int main(){
    int totalDias;
    int anos, semanas, dias;

    printf("Quantidade de dias: ");
    scanf("%d", &totalDias);

    anos = totalDias / 365;
    totalDias = totalDias % 365;

    semanas = totalDias / 7;
    dias = totalDias % 7;

    printf("%d ano(s), %d semana(s) e %d dia(s)\n", anos, semanas, dias);

    printf("\n");
    return 0;
}