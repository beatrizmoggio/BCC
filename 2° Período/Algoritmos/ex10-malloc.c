#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void print_vector(int n, int* v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

/*
1. Escreva uma função que aloca na heap um array de inteiros de tamanho n, preenchido com zeros,
e retorna seu endereço.
*/
int* create_vector(int n){
    int* v = malloc(n * sizeof(int));

    if (v == NULL) {
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        v[i] = 0; // inicializa todos as pos do vetor com zero
    }

    return v;
}


/*
2. Escreva uma função que receba um vetor de inteiros e seu tamanho n. A função deve retornar o
endereço de um novo vetor, alocado na heap, contendo os max maiores elementos contidos no
vetor original. OBS: você pode modificar o conteúdo do vetor original, se necessário.
*/
int* get_largest(int n, int* v, int max){
    // garante que não serão buscados mais elem do que existem no vetor
    if (max > n){
        max = n;
    }
    
    int * result = malloc(max * sizeof(int));
    if (result == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }
    

    for (int i = 0; i < max; i++){
        int maior = v[0]; // primeiro valor do vetor como maior
        int pos = 0; // salva sua posição
        
        // percorre o vetor procurando o maior valor atual
        for (int j = 1; j < n; j++){
            if (v[j] > maior){
                maior = v[j];
                pos = j;
            }
            
        }

        result[i] = maior; // add o maior encontrado no vetor result
        v[pos] = v[n - 1]; // coloca o último valor do vetor na pos do maior 
        n--; // diminui o tam do vetor = remove o último valor (duplicado)
    }
    
    return result;
}


/*
3. Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
uma cópia da string alocada na heap.
*/
char* copy_string(const char* str){
    int len = strlen(str); // calcula o tam da string
    char* copia = malloc((len + 1) * sizeof(char)); // aloca na mem uma copia incluindo o '\0' (len + 1)

    if (copia == NULL) {
        return NULL;
        printf("Erro ao alocar na memória.\n");
    }    
    
    for (int i = 0; i <= len; i++){
        copia[i] = str[i]; // copia caractere por caractere da string original, incluindo o '\0'
    }

    copia[i] = '\0';
    
    return copia;
}


/*
4. Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
uma cópia reversa da string alocada na heap.
*/
char* copy_reverse(const char* str){
    int len = strlen(str); // calcula o tam da string original
    char* copia = malloc((len + 1) * sizeof(char)); // +1 para o '\0'
    
    if (copia == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }
    
    for (int i = (len - 1); i >= 0 ; i--){ // inverte a string
        copia[len - 1 - i] = str[i]; // copia da última pos da original para a primeira da copia
    }
    
    return copia;
}


/* 5. Escreva uma função que concatene duas strings e retorne o resultado em uma nova string, alocada na heap. */
char* concat_string(const char* str1, const char* str2){
    int len1 = strlen(str1); // calcula o tam da str1
    int len2 = strlen(str2); // calcula o tam da str2
    int lenTotal = len1 + len2; // calcula o tam da strConcat
    char* strConcat = malloc((lenTotal + 1) * sizeof(char)); // +1 para o '\0'
    
    if (strConcat == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    // copia str1 para o inicio de strConcat
    for (int i = 0; i < len1; i++){
        strConcat[i] = str1[i]; 
    }
    
    // copia str2 em strConcat logo após o fim de str1 [i + len1]
    for (int i = 0; i < len2; i++){
        strConcat[i + len1] = str2[i]; 
    }
    
    strConcat[lenTotal] = '\0'; // termina a string com caractere nulo
    return strConcat;
}


/*
6. Escreva uma função que recebe um array de strings (matriz de char) e a quantidade de strings
contidas. A função deve concatenar todas as strings, separadas por espaço, em uma só, a ser
alocada na heap e ter seu endereço retornado.
*/
char* stringcat_all(int n, char str[n][51]){
    int maxSize = 0; // variável que soma o n° total de caracteres para a string resultante

    // percorre todas as palavras dentro da matriz str
    for (int i = 0; i < n; i++){
        maxSize += strlen(str[i]); // devolve o tamanho de cada palavra (sem contar '\0') e soma em maxSize
    }
    
    // +1: o caractere '\0' ao final da string concatenada.
    // + (n-1): os espaços simples (" ") que serão inseridos entre as palavras.
    maxSize += 1 + (n-1);
    
    char* res = malloc(maxSize * sizeof(char));
    res[0] = 0; // Coloca '\0' na primeira posição para funcionar strcat

    if (res == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    // strcat localiza o '\0'
    for (int i = 0; i < n; i++){
        strcat(res, str[i]); // add a palavra str[i] ao final de res
        strcat(res, " "); // add o espaço " " ao final de res
    }
    
    return res;
}


/*
7. Escreva uma função que realize a união entre dois vetores, retornando o resultado em um vetor
alocado na heap. Considere que não há elementos repetidos dentro de um mesmo vetor. O
tamanho do vetor resultante deverá ser retornado pelo parâmetro n3.
*/
int* array_union(const int* v1, int n1, const int* v2, int n2, int* n3){
    int maxSize = n1 + n2; // tam max da união
    int* v3 = malloc(maxSize * sizeof(int));

    if (v3 == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    int countRes = 0; // conta quantos elem foram adicionados ao vetor união (v3)

    for (int i = 0; i < n1; i++){
        v3[countRes++] = v1[i]; // todos os elem de v1 são incluídos em v3
    }

    for (int i = 0; i < n2; i++){
        int repetido = 0; // para cada elem de v2, vamos verificar se ja ta em v3

        for (int j = 0; j < countRes; j++){
            if (v2[i] == v3[j]){ // compara v2[i] com todos os elementos já inseridos em v3
                repetido = 1; // se encontrar igual marca como repetido
                break; // interrompe o loop
            }
        }
        
        if (!repetido){ // se não for repetido
            v3[countRes++] = v2[i]; // add v2[i] em v3
        }
    }
    
    *n3 = countRes; // salva o tam final do vetor união (v3)
    return v3;
}


/*
8. Escreva uma função que realize a intersecção entre dois vetores, retornando o resultado em um
vetor alocado na heap. Considere que não há elementos repetidos dentro de um mesmo vetor. O
tamanho do vetor resultante deverá ser retornado pelo parâmetro n3.
*/
int* array_intersection(const int* v1, int n1, const int* v2, int n2, int* n3){
    int maxSize = 0;

    // o max possivel de elem na interseção é o tam do menor vetor
    if (n1 < n2){
        maxSize = n1;
    } else {
        maxSize = n2;
    }
    
    int* v3 = malloc(maxSize * sizeof(int));

    if (v3 == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    int countRes = 0; // conta quantos elem foram adicionados ao vetor interseção (v3)

    for (int i = 0; i < n1; i++){ // para cada elem de v1
        for (int j = 0; j < n2; j++){ // compara com todos os elem de v2
            if (v1[i] == v2[j]){ // se encontrar elem igual
                v3[countRes++] = v1[i]; // add ao v3 e conta +1 no countRes
                break; // não precisa continuar comparando o v1[i]
            }
        }
    }

    *n3 = countRes; // salva o tam final do vetor interseção (v3)
    return v3;
}


/*
9. Escreva uma função que recebe o endereço de um vetor alocado em heap, seu tamanho atual e
um novo tamanho para o vetor. A função deve alocar um vetor com o novo tamanho na heap,
iniciá-lo com zeros e copiar todos os elementos do vetor original para o novo. O vetor original deve,
então, ser liberado da heap pela função free(). A função deve retornar o endereço do novo vetor.
OBS: a função também pode ser usada para diminuir o vetor original. Nesse caso, a quantidade de
elementos do vetor original a ser copiada ficará restrita ao tamanho do novo vetor.
*/
// essa função é utilizada somente no main, e não dentro da função expand
void fill(int* v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100; // preenche o vetor com números aleatórios entre 0 e 99
    }
}

int* expand(int* v, int n, int new_n){
    int* novo = malloc(new_n * sizeof(int)); // aloca na heap um novo vetor de tamanho new_n

    if (novo == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    for (int i = 0; i < new_n; i++) {
        novo[i] = 0; // inicializa todas as posições do novo vetor com zero
    }

    // define quantos elementos do vetor antigo devem ser copiados:
    int limite = 0;
    if (n < new_n){ // se o tam do vetor antigo é menor que do vetor novo, então:
        limite = n; // copia todo o vetor antigo
    } else { // se é ao contrário: tam do vetor novo é menor que do vetor antigo, então:
        limite = new_n; // copia só até o tam do vetor novo: new_n
    }
    

    for (int i = 0; i < limite; i++){
        novo[i] = v[i]; // copia todos os valores do vetor antigo para o vetor novo, até o limite
    }
    
    free(v);
    return novo;
}


/*
10. Escreva uma função que recebe o endereço de um vetor de vetor de inteiros (matriz de inteiros),
chamado vec, e suas dimensões (rows e cols). A função deve retornar o endereço de um vetor
alocado na heap, de tamanho rows, contendo as somas de cada um dos vetores contidos em vec.
*/
int* totals(int rows, int cols, int vec[rows][cols]){
    int* somas = malloc(rows * sizeof(int));

    if (somas == NULL){
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    // percorre cada linha da matriz
    for (int i = 0; i < rows; i++){
        int soma = 0; // armazena a soma dos elementos da linha atual

        // percorre cada coluna da matriz
        for (int j = 0; j < cols; j++){
            soma = soma + vec[i][j]; // soma todos os valores da linha i, coluna por coluna
        }

        somas[i] = soma; // armazena a soma da linha[i]
    }
    
    return somas;
}


int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);
    
        if (nEx == 1) {
            int* v1 = create_vector(7); // aloca array de 7 inteiros na heap
            print_vector(7, v1); // imprime 0,0,0,0,0,0,0
            free(v1); // Libera a memória alocada
            
            printf("\n");
        
        } else if (nEx == 2) {
            int v0[] = {6, 10, 2, 1, 2, 3, 9};
            int* v1 = get_largest(7, v0, 2); // retorna vetor com os 2 maiores valores de v0
            print_vector(2, v1); // imprime 10,9
            free(v1); // Libera a memória alocada

            printf("\n");

        } else if (nEx == 3) {
            const char* original = "UTFPR - Campo Mourao";
            char* copia = copy_string(original);

            printf("Original: %s\n", original);
            printf("Cópia: %s\n", copia);

            free(copia); // Libera a memória alocada

            printf("\n");

        } else if (nEx == 4) {
            const char* original = "UTFPR - Campo Mourao";
            char* copia = copy_reverse(original);

            printf("Original: %s\n", original);
            printf("Cópia Reversa: %s\n", copia);

            free(copia); // Libera a memória alocada

            printf("\n");

        } else if (nEx == 5) {
            const char* str1 = "UTFPR";
            const char* str2 = " Campo Mourao";
            printf("STR1: %s\n", str1);
            printf("STR2:%s\n", str2);

            char* c = concat_string(str1, str2);
            printf("STR Concatenada: %s\n", c);
            free(c); // Libera a memória alocada

            printf("\n");

        } else if (nEx == 6) {
            char words[][51] = {"Um", "Dois", "Três", "Quatro"};
            char* res = stringcat_all(4, words);
            printf("%s\n", res);
            
            free(res);
            printf("\n");

        } else if (nEx == 7) {
            int v1[] = {1, 3, 2, 5, 4};
            int v2[] = {3, 6, 7, 4};

            printf("\nVetor 1: ");
            for (int i = 0; i < 5; i++){
                printf("%d ", v1[i]);
            }

            printf("\nVetor 2: ");
            for (int i = 0; i < 4; i++){
                printf("%d ", v2[i]);
            }
            
            int n3;
            int* v3 = array_union(v1, 5, v2, 4, &n3);
            
            printf("\nUnion: ");
            print_vector(n3, v3);
            free(v3);

            printf("\n");

        } else if (nEx == 8) {
            int v1[] = {1, 3, 2, 5, 4};
            int v2[] = {3, 6, 7, 4};

            printf("\nVetor 1: ");
            for (int i = 0; i < 5; i++){
                printf("%d ", v1[i]);
            }

            printf("\nVetor 2: ");
            for (int i = 0; i < 4; i++){
                printf("%d ", v2[i]);
            }

            int n3;
            int* v3 = array_intersection(v1, 5, v2, 4, &n3);

            printf("\nIntersection: ");
            print_vector(n3, v3);
            free(v3);

            printf("\n");

        } else if (nEx == 9) {
            int* v = malloc(10 * sizeof(int));
            fill(v, 10); // preenche o vetores randômicos
            v = expand(v, 10, 20); // expande o vetor para 20 elementos
            print_vector(20, v);
            free(v);

            printf("\n");

        } else if (nEx == 10) {
            int v[3][4] = { {1,0,3,5}, {2,4,7,1}, {5,3,3,1} };
            int* sum = totals(3, 4, v);
            // sum = {9, 14, 12}

            printf("Vetor de somas: ");
            for (int i = 0; i < 3; i++) {
                printf("%d ", sum[i]);  // Esperado: 9 14 12
            }

            free(sum);
            printf("\n");

        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}