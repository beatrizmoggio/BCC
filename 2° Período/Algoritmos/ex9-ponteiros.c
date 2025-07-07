#include <stdio.h>
#include <string.h>

void add(int* a, int* b){
    *a = *a + *b;
}

void print_vector(int n, const int* v){
    for (int i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("Endereço de %d: %p\n", *(v + i), (void*)(v + i));
    }
}


void print_vector_reverse(int n, const int* v){
    for (int i = n - 1; i >= 0; i--){
        printf("%d ", *(v + i));
    }
    
    printf("\n");

    for (int i = n - 1; i >= 0; i--){
        printf("Endereço de %d: %p\n", *(v + i), (void*)(v + i));
    }
}


void get_min_max(int n, const int* v, int* min, int* max){
    *min = *v;
    *max = *v;

    for (int i = 0; i < n; i++){
        if (*(v + i) < *min){
            *min = *(v + i);
        } if (*(v + i) > *max){
            *max = *(v + i);
        }                   
    }
}


void print_vector2D(int rows, int cols, const int* v){
    for (int i = 0; i < rows*cols; i++){
        printf("%d ", *(v));
        v++;
    }
    printf("\n");
}


void make_mirrored(char* s){
    int n = strlen(s);
    char* p = s + n;
    *p = '|';
    s = p - 1;

    for (int i = 0; i < n; i++){
        p++;
        *p = *s;
        s--;
    }

    p++;
    *p = 0;
}


char* find_most_similar(const char* str, int n, char list[][50]){
    int dist = -1;
    char* similar = NULL;

    for (int i = 0; i < n; i++){
        int hamming = get_hamming_distance(str, *(list + i));

        if (dist == -1 || hamming < dist){ //primeiro valor de hamming já é o menor
            dist = hamming;
            similar = *(list + i);
        }      
    }
    
    return similar;
}


typedef struct {
    int id;
    char name[51];
    int type; // [1..10]
} Contact;


int find_by_name(int n, const Contact* vec, const char* find){
    int cont = 0;

    for (int i = 0; i < n; i++){
        if (strstr((vec + i)->name, find)){
            cont++;
        }
    }

    return cont;
}


void count_types(int n, const Contact* vec){
    int cont[9] = {0};

    for (int i = 0; i < n; i++){
        int tipo = (vec + i)->type;

        if (tipo >= 1 && tipo <= 9){
            (*(cont + (tipo - 1)))++;
        }
    }
    
    for (int i = 0; i < 9; i++){
        printf("Tipo %d: %d contatos\n", i + 1, *(cont + i));
    }
}


void count_types(int n, const Contact* vec){
    int count[11] = {0};

    for (int i = 0; i < n; i++){
        if ((vec + i)->type >= 1 && (vec + i)->type <= 9){
            *(count + (vec + i)->type) = *(count + (vec + i)->type);
        }
    }
    
    printf("Contatos por tipo:\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(count + i));
    }
    printf("]\n");
}


typedef struct Product {
    int id; // identificador do produto
    int stock; // estoque do produto
    char name[101]; // nome do produto
} Product;


void check_stock(int n1, const Product* prods, int* n2, int* orders) {
    for (int i = 0; i < n1; i++) {
        const Product* aux = prods + i;

        if (aux->stock <= 0) {
            int found = 0;

            for (int j = 0; j < *n2; j++) {
                if (*(orders + j) == aux->id) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                *(orders + *n2) = aux->id;
                (*n2)++;
            }
        }
    }
}


int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);
    
        if (nEx == 1) {
            char c = 'A';
            int i = 42;
            double d = 3.14;

            char *pc = &c;
            int *pi = &i;
            double *pd = &d;

            printf("Endereço c (char):      %p\n", (void*)pc);
            printf("Endereço i (int):       %p\n", (void*)pi);
            printf("Endereço d (double):    %p\n", (void*)pd);
            printf("\n");
        
        } else if (nEx == 2) {
            int a = 10;
            int b = 5;

            printf("Antes: a = %d, b = %d\n", a, b);
            add(&a, &b);
            printf("Depois: a = %d, b = %d\n", a, b);
            
            printf("\n");

        } else if (nEx == 3) {
            int v[] = {10, 20, 30, 40, 50};
            int n = sizeof(v) / sizeof(v[0]);

            print_vector(n, v);
            printf("\n");

        } else if (nEx == 4) {
            int v[] = {10, 20, 30, 40, 50};
            int n = sizeof(v) / sizeof(v[0]);

            print_vector_reverse(n, v);
            printf("\n");

        } else if (nEx == 5) {
            int min, max;
            int v[] = {10, 20, 30, 40, 50};
            int n = sizeof(v) / sizeof(v[0]);

            get_min_max(n, v, &min, &max);
            printf("Mínimo: %d\n", min);
            printf("Máximo: %d\n", max);
            printf("\n");

        } else if (nEx == 6) {
            int v[3][4] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
            };

            print_vector2D(3, 4, (int*)v);
            printf("\n");

        } else if (nEx == 7) {
            char str[40] = "hello";

            make_mirrored(str);
            printf("String espelhada: %s\n", str);

            printf("\n");

        } else if (nEx == 8) {
            char words[][50] = {"batati", "savata", "cabana", "haluha"};
            char* most_similar = find_most_similar("banana", 4, words);
            printf("Mais parecida: %s\n\n", most_similar); // "cabana"
            
            
        } else if (nEx == 9) {
            Contact contatos[] = {
                {1, "Maria Silva", 3},
                {2, "Carlos Santos", 4},
                {3, "Mariana Oliveira", 2},
                {4, "Ana Maria", 1}
            };
            
            int resultado = find_by_name(4, contatos, "Maria");
            
            printf("Encontrados: %d contatos com 'Maria' no nome.\n\n", resultado);
            

        } else if (nEx == 10) {
            Contact lista[] = {
                {1, "Alice", 1},
                {2, "Bob", 3},
                {3, "Carlos", 1},
                {4, "Diana", 10},
                {5, "Eva", 3},
                {6, "Fábio", 2}
            };

            // Chama a função com 6 contatos
            count_types(6, lista);


        } else if (nEx == 11) {
            Product prods[] = {
                {101, 0}, {102, 5}, {103, -3}, {104, 0},
                {101, -1}, {103, 0}
            };

            int orders[10] = {0};
            int n2 = 0;  // contador que deve ser passado como ponteiro

            check_stock(6, prods, &n2, orders);

            printf("IDs para repor:\n");
            for (int i = 0; i < n2; i++) {
                printf("%d\n", orders[i]);
            }

        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}