#include <stdio.h>
#include <stdlib.h>


void print_matrix(int rows, int cols, int m[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}


void print_reversed(int rows, int cols, int m[rows][cols]){
    for (int i = rows - 1; i >= 0; i--){
        for (int j = cols - 1; j >= 0; j--){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}


void print_min_max(int rows, int cols, int m[rows][cols]){
    int max, min;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (m[i][j] > max){
                max = m[i][j];
            
            } if (m[i][j] < min){
                min = m[i][j];
            }            
        }
    }

    printf("Valor máximo: %d\n", max);
    printf("Valor mínimo: %d\n", min);
    printf("\n");
}


float average(int rows, int cols, int m[rows][cols]){
    int soma = 0, cont = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            soma = soma + m[i][j];
            cont++;
        }
    }
    
    float media = soma / cont;
    return media;
}


void init_values(int rows, int cols, int m[rows][cols], int start, int step){
    int x = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            m[i][j] = start + (step * x);
            printf("%d ", m[i][j]);
            x++;
        }
        printf("\n");
    }
    printf("\n");    
}


void init_random(int rows, int cols, int m[rows][cols], int min, int max){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            int aleat = min + (rand() % (max - min + 1));
            m[i][j] = aleat;
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int max_line(int rows, int cols, int m[rows][cols]){
    int somaMax = 0, linha = 0;

    for (int i = 0; i < rows; i++){
        int soma = 0;

        for (int j = 0; j < cols; j++){
            soma = soma + m[i][j];
        }

        if (soma > somaMax){
            somaMax = soma;
            linha = i + 1;
        }
    }

    return somaMax;
}


void put_totals(int rows, int cols, int m[rows][cols]){
    for (int i = 0; i < rows; i++){
        int soma = 0;

        for (int j = 0; j < cols; j++){
            soma = soma + m[i][j];
        }

        m[i][cols] = soma;
    }
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}


int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    if (r1 != r2 || c1 != c2){
        return 0;
    }    

    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            if (m1[i][j] != m2[i][j]){
                return 0;
            }
        } 
    }

    return 1;
}


void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            m3[i][j] = m1[i][j] + m2[i][j];
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void transpose(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            m2[j][i] = m1[i][j];
        }  
    }

    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
    printf("\n");   
}


void switch_diagonals(int d, int m1[d][d]){
    for (int i = 0; i < d; i++){
        int temp = m1[i][i];
        m1[i][i] = m1[i][d - 1 - i];
        m1[i][d - 1 - i] = temp;
    }
    
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void pascal_triangle(int n){
    
}




int main() {
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);

        if (nEx == 1) {
            int mat[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            print_matrix(3, 3, mat);


        } else if (nEx == 2) {
            int mat[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            print_reversed(3, 3, mat);


        } else if (nEx == 3) {
            int mat[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            print_min_max(3, 3, mat);
            
        
        } else if (nEx == 4) {
            int mat[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            float media = average(3, 3, mat);
            printf("Média aritmética simples: %.2f\n\n", media);
            
        
        } else if (nEx == 5) {
            int v[4][6];
            init_values(4, 6, v, 10, 2); // start=10, step=2
            
        
        } else if (nEx == 6) {
            int v[4][6];
            init_random(4, 6, v, 5, 50); // min=5, max=50
            
        
        } else if (nEx == 7) {
            int mat[5][5] = {
                { 1, 2, 3, 4, 5}, // soma: 15
                { 2, 4, 6, 8,10}, // soma: 30 ← esta linha possui a maior soma
                { 1, 2, 3, 4, 7}, // soma: 17
                { 2, 0, 6, 1,10}, // soma: 19
                { 7, 3, 4, 0, 0} // soma: 14
            };
            int maxSoma = max_line(5, 5, mat);
            printf("Maior soma: %d\n", maxSoma);

        
        } else if (nEx == 8) {
            int mat[4][5] = {
                { 1, 2, 3, 4, 0},
                { 2, 4, 6, 8, 0},
                { 3, 6, 9, 12, 0},// O último elemento de cada linha receberá a soma
                { 4, 8, 12,16, 0} // da linha.
            };
            put_totals(4, 5, mat);

        
        } else if (nEx == 9) {
            int m1[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            int m2[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };

            if (matrix_equals(3, 3, m1, 3, 3, m2)){
                printf("As matrizes são iguais.\n\n");
            } else {
                printf("As matrizes são diferentes.\n\n");
            }

        
        } else if (nEx == 10) {
            int m1[3][2] = {
                {1, 3},
                {1, 0},
                {1, 2}
            };

            int m2[3][2] = {
                {0, 0},
                {7, 5},
                {2, 1}
            };

            int m3[3][2];
            sum(3, 2, m1, m2, m3);
            
        
        } else if (nEx == 11) {
            int m1[2][3] = {
                {1, 2, 3},
                {0, 6, 7}
            };

            int m2[3][2];

            transpose(2, 3, m1, 3, 2, m2);
            
        
        } else if (nEx == 12) {
            int m1[3][3] = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            };
            switch_diagonals(3, m1);


        } else if (nEx == 13) {
            


        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}