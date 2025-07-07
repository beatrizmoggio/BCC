#include <stdio.h>

int main(){
    int a, b;

    printf("A: ");
    scanf("%d", &a);
    
    printf("A: ");
    scanf("%d", &a);

    float resto1 = a % b;
    float resto2 = a - (a/b) * b;

    printf("Resto com: %.2f\n", resto1);
    printf("Resto sem: %.2f\n", resto2);

    printf("\n");
    return 0;
}