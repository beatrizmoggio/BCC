#include <stdio.h>
#include <string.h>


char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}


void print_string(char str[]){
    int i = 0;
    
    // enquanto o caractere atual não for o caractere nulo '\0' (fim da string)
    while (str[i] != '\0'){
        printf("%c ", str[i]);
        i++;
    }   
}


// (02 - a) FUNÇÃO QUE IMPRIME UMA STRING DE TRÁS PARA FRENTE (com strlen)
void print_string_reversed1(char str[]){
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--){ // percorre a string de trás para frente
        printf("%c", str[i]);
    }
}
 

// (02 - b) FUNÇÃO QUE IMPRIME UMA STRING DE TRÁS PARA FRENTE (sem strlen)
void print_string_reversed2(char str[]){
    int len = 0;

    while (str[len] != '\0'){
        len++;
    }

    for (int j = len - 1; j >= 0; j--){ // percorre a string de trás para frente
        printf("%c", str[j]);
    }
}


// (03) FUNÇÃO QUE CONTA QUANTAS LETRAS, DÍGITOS E SÍMBOLOS TEM UMA STRING
void string_report(char str[]){
    int i = 0;
    int letras = 0;
    int digitos = 0;
    int simbolos = 0;

    while (str[i] != '\0'){
        char c = str[i];

        if (c >= 32 && c <= 126){
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                letras++;
            } else if (c >= '0' && c <= '9'){
                digitos++;
            } else {
                simbolos++;
            }           
        }
        
        i++;
    }

    printf("\nLetras: %d", letras);
    printf("\nDígitos: %d", digitos);
    printf("\nSímbolos: %d", simbolos);
}


// (04) FUNÇÃO QUE TRANSFORMA UMA STRING EM MAIÚSCULA
void string_to_upper(char str[]){
    int i = 0;

    while (str[i] != '\0'){
        char c = str[i];

        if (c >= 'a' && c <= 'z'){
            str[i] = c - 32;
        }

        printf("%c", str[i]);
        i++;
    }
}


// (05) FUNÇÃO QUE COMPARA DUAS STRINGS
void strcmp_plus(const char str1[], const char str2[]){
    int i = 0;

    // transforma a str1 em maiúscula
    while ((str1[i] != '\0') && (str2[i] != '\0')){
        char c1 = to_upper(str1[i]);
        char c2 = to_upper(str2[i]);

        if (c1 != c2){
            if (c1 < c2){
                printf("Resultado: str1 vem antes de str2 (res < 0)");
            } else {
                printf("Resultado: str1 vem depois de str2 (res > 0)");
            }

            return;
        }
        
        i++;
    }

    char c1 = to_upper(str1[i]);
    char c2 = to_upper(str2[i]);

    if (c1 == c2) {
        printf("Resultado: str1 é igual a str2 (res = 0)");
    } else if (c1 < c2) {
        printf("Resultado: str1 vem antes de str2 (res < 0)");
    } else {
        printf("Resultado: str1 vem depois de str2 (res > 0)");
    }
}


int main(){
    char str[] = "Ola, como vai?";
    const char str1[] = "Bom dia 29/04/2025!";
    const char str2[] = "Boa noite 29/04/2025!";

    strcmp_plus(str1, str2);

    printf("\n\n");
    return 0;
}