#include <stdio.h>

int main(){
    int num;

    printf("Número da tabuada: ");
    scanf("%d", &num);

    for (int i = 1; i <= 5; i++)
    {
        int valor = num * i;
        int prox = 5 + i;

        printf("%d x %2d = %d\t", num, i, valor);
        printf("%d x %2d = %d\n", num, prox, valor);
    }
    
    printf("\n");
    return 0;
}