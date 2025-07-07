#include <stdio.h>

int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);

        if (nEx == 1) {
            int linhas;
            printf("Número de linhas: ");
            scanf("%d", &linhas);

            for (int i = linhas; i > 0; i--){
                printf("Linha %d\n", i);
            }
            
            printf("\n");

        } else if (nEx == 2) {
            printf("DEC OCT HEX CHR\n");
            for (int i = 33; i <= 126; i++) {
                printf("%03d %03o %03X %02c\n", i, i, i, i);
            }

            printf("\n");
            
        } else if (nEx == 3) {
            int num, soma = 0, impar = 1;
            printf("Informe um número: ");
            scanf("%d", &num);

            for (int i = 1; i <= num; i++){
                printf("%d", impar);
                soma += impar;
                impar += 2;

                if (i < num){
                    printf(" + ");
                }
                
            }

            printf(" = %d\n", soma);
            printf("\n");
        
        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}