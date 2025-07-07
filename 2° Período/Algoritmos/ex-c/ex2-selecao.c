#include <stdio.h>

void imprimirPorExtenso(int num) {
    int unidade, dezena, centena, milhar;

    milhar = num / 1000;
    num %= 1000; // resto por 1000

    centena = num / 100;
    num %= 100; // resto por 100
    
    dezena = num / 10;
    unidade = num % 10;

    if (milhar > 0) {
        if (milhar == 1) {
            printf("mil ");
        } else {
            printf("%d mil ", milhar);
        }
    }

    if (centena > 0) {
        if (centena == 1 && dezena == 0 && unidade == 0) {
            printf("cem ");
        } else {
            switch (centena) {
                case 2: printf("duzentos "); break;
                case 3: printf("trezentos "); break;
                case 4: printf("quatrocentos "); break;
                case 5: printf("quinhentos "); break;
                case 6: printf("seiscentos "); break;
                case 7: printf("setecentos "); break;
                case 8: printf("oitocentos "); break;
                case 9: printf("novecentos "); break;
            }
        }
    }

    if (dezena > 1) {
        switch (dezena) {
            case 2: printf("vinte "); break;
            case 3: printf("trinta "); break;
            case 4: printf("quarenta "); break;
            case 5: printf("cinquenta "); break;
            case 6: printf("sessenta "); break;
            case 7: printf("setenta "); break;
            case 8: printf("oitenta "); break;
            case 9: printf("noventa "); break;
        }

        if (unidade > 0) {
            printf("e ");
            switch (unidade) {
                case 1: printf("um "); break;
                case 2: printf("dois "); break;
                case 3: printf("três "); break;
                case 4: printf("quatro "); break;
                case 5: printf("cinco "); break;
                case 6: printf("seis "); break;
                case 7: printf("sete "); break;
                case 8: printf("oito "); break;
                case 9: printf("nove "); break;
            }
        }
    } else if (dezena == 1) {
        switch (unidade) {
            case 0: printf("dez "); break;
            case 1: printf("onze "); break;
            case 2: printf("doze "); break;
            case 3: printf("treze "); break;
            case 4: printf("quatorze "); break;
            case 5: printf("quinze "); break;
            case 6: printf("dezesseis "); break;
            case 7: printf("dezessete "); break;
            case 8: printf("dezoito "); break;
            case 9: printf("dezenove "); break;
        }
    } 
}


int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);

        if (nEx == 1) {
            float num, valorAbs;
            printf("Digite um número: ");
            scanf("%f", &num);

            if (num >= 0){
                printf("O valor absoluto é %f.\n", num);
            } else {
                valorAbs = num * (-1);
                printf("O valor absoluto é |%.2f|.\n", valorAbs);
            }
            
            printf("\n");

        } else if (nEx == 2) {
            int num;
            printf("Digite um número inteiro: ");
            scanf("%d", &num);

            if (num < 0 || num > 9){
                printf("Erro: número fora do intervalo permitido (0-9).\n");
            } else {
                printf("Número por extenso: ");
                switch (num){
                    case 0: printf("zero.\n"); break;
                    case 1: printf("um.\n"); break;
                    case 2: printf("dois.\n"); break;
                    case 3: printf("três.\n"); break;
                    case 4: printf("quatro.\n"); break;
                    case 5: printf("cinco.\n"); break;
                    case 6: printf("seis.\n"); break;
                    case 7: printf("sete.\n"); break;
                    case 8: printf("oito.\n"); break;
                    case 9: printf("nove.\n"); break;
                }
            }
            
            printf("\n");
            
        } else if (nEx == 3) {
            int num;
            printf("Digite um número inteiro: ");
            scanf("%d", &num);

            if (num % 2 == 0){
                printf("O número %d é par.\n", num);
            } else {
                printf("O número %d é ímpar.\n", num);
            }
            
            printf("\n");
            
        } else if (nEx == 4) {
            int ano;
            printf("Digite um ano: ");
            scanf("%d", &ano);

            if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)){
                printf("%d é um ano bissexto.\n", ano);
            } else {
                printf("%d não é um ano bissexto.\n", ano);
            }
            
            printf("\n");
            
        } else if (nEx == 5) {
            float n1, n2, n3, media;
            printf("Nota 1 [0-10]: ");
            scanf("%f", &n1);

            printf("Nota 2 [0-10]: ");
            scanf("%f", &n2);

            printf("Nota 3 [0-10]: ");
            scanf("%f", &n3);

            if ((n1 < 0 || n1 > 10) || (n2 < 0 || n2 > 10) || (n3 < 0 || n3 > 10)){
                printf("Erro: todas as notas devem estar no intervalo de 0 à 10.\n\n");
                return 1;
            }

            media = (n1 + n2 + n3) / 3;

            if (media >= 8.5){
                printf("Média: %.2f = CONCEITO A.\n", media);

            } else if (media >= 7 && media < 8.5){
                printf("Média: %.2f = CONCEITO B.\n", media);

            } else if (media >= 5.5 && media < 7){
                printf("Média: %.2f = CONCEITO C.\n", media);

            } else if (media < 5.5){
                printf("Média: %.2f = CONCEITO D.\n", media);
            }
            
            printf("\n");
            
        } else if (nEx == 6) {
            int a, b, c, d, maior;

            printf("Número A: ");
            scanf("%d", &a);

            printf("Número B: ");
            scanf("%d", &b);

            printf("Número C: ");
            scanf("%d", &c);

            printf("Número D: ");
            scanf("%d", &d);

            maior = a;

            if (b > maior){
                maior = b;
            }

            if (c > maior){
                maior = c;
            }
            
            if (d > maior){
                maior = d;
            }
            
            printf("O maior número informado é: %d.\n", maior);
            printf("\n");
            
        } else if (nEx == 7) {
            int a, b, c, maior, meio, menor;

            printf("Número A: ");
            scanf("%d", &a);

            printf("Número B: ");
            scanf("%d", &b);

            printf("Número C: ");
            scanf("%d", &c);

            if (a <= b && a <= c){
                menor = a;

                if (b <= c){
                    meio = b;
                    maior = c;
                } else {
                    meio = c;
                    maior = b;
                }
            }

            else if (b <= a && b <= c){
                menor = b;

                if (a <= c){
                    meio = a;
                    maior = c;
                } else {
                    meio = c;
                    maior = a;
                }
            }
            
            else {
                menor = c;

                if (a <= b){
                    meio = a;
                    maior = b;
                } else {
                    meio = b;
                    maior = a;
                }
            }
            
            printf("Ordem crescente: %d, %d, %d.\n", menor, meio, maior);
            printf("\n");
            
        } else if (nEx == 8) {
            int num;

            printf("Digite um número inteiro de até 4 dígitos: ");
            scanf("%d", &num);

            imprimirPorExtenso(num);
            printf("\n");
            
        } else if (nEx == 9) {
            int num, unidade, dezena, centena, milhar, dezmilhar;
            printf("Digite um número de 5 dígitos: ");
            scanf("%d", &num);

            printf("Os dígitos do número %d são:\n", num);

            unidade = num % 10;
            num = num / 10;
            
            dezena = num % 10;
            num = num / 10;

            centena = num % 10;
            num = num / 10;

            milhar = num % 10;
            num = num / 10;

            dezmilhar = num % 10;

            printf("Dezmilhar: %d\n", dezmilhar);
            printf("Milhar: %d\n", milhar);
            printf("Centena: %d\n", centena);
            printf("Dezena: %d\n", dezena);
            printf("Unidade: %d\n", unidade);
            printf("\n");
            
        } else if (nEx == 12) {
            char op;
            int a, b;
            float res;

            printf("Digite a operação (+ - * / %%): ");
            scanf(" %c", &op); 

            printf("Número A: ");
            scanf("%d", &a);

            printf("Número B: ");
            scanf("%d", &b);

            printf("\n[ CALCULADORA SIMPLEX ]\n");
            printf("Operador> %c\n", op);
            printf("Número A> %d\n", a);
            printf("Número B> %d\n", b);

            if (op == '+') {
                res = a + b;
                printf("%d %c %d = %.2f\n", a, op, b, res);

            } else if (op == '-') {
                res = a - b;
                printf("%d %c %d = %.2f\n", a, op, b, res);

            } else if (op == '*') {
                res = a * b;
                printf("%d %c %d = %.2f\n", a, op, b, res);

            } else if (op == '/') {
                if (b == 0) {
                    printf("Erro: divisão por zero!\n");
                } else {
                    res = (float)a / b;
                    printf("%d %c %d = %.2f\n", a, op, b, res);
                }

            } else if (op == '%') {
                if (b == 0) {
                    printf("Erro: divisão por zero!\n");
                } else {
                    int mod = a % b;
                    printf("%d %% %d = %d\n", a, b, mod);
                }

            } else {
                printf("Operador inválido!\n");
            }

            printf("\n");
            
        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}