#include <stdio.h>

void print_even(int n, int vet[]){
    for (int i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            printf("%d ", vet[i]);
        }
    }
    printf("\n\n");
}


void set_positive(int n, int vet[]) {
    for (int i = 0; i < n; i++){
        if (vet[i] < 0){
            vet[i] = vet[i] * (-1);
        }
        printf("%d ", vet[i]);
    }
    printf("\n\n");
}


void find_max(int n, int vet[]) {
    int maior = vet[0];
    for (int i = 1; i < n; i++){
        if (maior < vet[i]){
            maior = vet[i];
        }
    }
    printf("\nMaior valor do vetor: %d\n\n", maior);
}


void replace_all(int n, int vet[], int elem) {
    int cont = 0;
    for (int i = 0; i < n; i++){
        if (vet[i] == elem){
            cont++;
        }
    }
    printf("\nO elemento %d aparece %d vezes no vetor\n\n", elem, cont);
}


void read_vector(int n, int vet[]){
    int i = 0;

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    printf("\nVetor lido: ");
    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }

    printf("\n\n");
}


int is_sorted(int n, int vet[]){
    for (int i = 0; i < n - 1; i++){
        if (vet[i] > vet[i + 1]){
            return 0;
        }
    }
    return 1;
}


void distances(int n, int points[]) {
    for (int i = 0; i < n - 1; i++) {
        int x1 = points[2*i];
        int y1 = points[2*i + 1];
        int x2 = points[2*i + 2];
        int y2 = points[2*i + 3];

        double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        printf("Distância entre o ponto (%d, %d) e o ponto (%d, %d): %.2f\n", x1, y1, x2, y2, distance);
    }

    printf("\n\n");
}


void reverse(int n, int vet[]){
    int i = 0;
    int j = n - 1;

    while (i < j){
        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
        i++; j--;
    }
}


void vector_copy(int n, int vet1[], int vet2[]){
    for (int i = 0; i < n; i++){
        vet2[i] = vet1[i];
    }   
}


int vector_insert(int n, int vet[], int elem){
    for (int i = 0; i < n; i++){
        if (vet[i] == -1){
            vet[i] = elem;
            break;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
}


void vector_remove(int n, int vet[], int pos){
    if (pos >= 0 && pos < n){
        vet[pos] = -1;
    }
        
    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    
}


void vector_defrag(int n, int vet[n]){
    int j = 0;

    for (int i = 0; i < n; i++){
        if (vet[i] != -1){
            vet[j++] = vet[i];
        }
    }

    while (j < n){
        vet[j++] = -1;
    }

    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
}


void vector_concat(int n1, int vet1[n1], int n2, int vet2[n2], int vet3[]){
    for (int i = 0; i < n1; i++){
        vet3[i] = vet1[i];
    }

    for (int i = 0; i < n2; i++){
        vet3[n1 + i] = vet2[i];
    }
    
    for (int i = 0; i < (n1+n2); i++){
        printf("%d ", vet3[i]);
    }
}


void merge(int n1, int vet1[], int n2, int vet2[], int vet3[]){
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2){
        if (vet1[i] < vet2[j]){
            vet3[k] = vet1[i];
            i++;
        } else {
            vet3[k] = vet2[j];
            j++;
        }

        k++;
    }

    // copia o restante de vet1
    while (i < n1){
        vet3[k] = vet1[i];
        i++; k++;
    }
    
    // copia o restante de vet2
    while (j < n2){
        vet3[k] = vet2[j];
        j++; k++;
    }

    for (int i = 0; i < (n1 + n2); i++){
        printf("%d ", vet3[i]);
    }
}


int max_num_slice2(int n, int vet[]){
    int maxAtual = vet[0];
    int maxGlobal = vet[0];

    for (int i = 1; i < n; i++){
        if (maxAtual + vet[i] > vet[i]){
            maxAtual = maxAtual + vet[i];
        } else {
            maxAtual = vet[i];
        }
        
        if (maxAtual > maxGlobal){
            maxGlobal = maxAtual;
        }
    }
    
    return maxGlobal;
}


void count_elements(int n, int vet[]){
    for (int i = 0; i < n; i++){
        int cont = 1;
        int contado = 0;

        for (int j = 0; j < i; j++){
            if (vet[i] == vet[j]){
                contado = 1;
                break;
            }
        }
        
        if (!contado){
            for (int j = i + 1; j < n; j++){
                if (vet[i] == vet[j]){
                    cont++;
                }
            }
            
            if (cont > 1){
                printf("\n> Número %d aparece %d vezes", vet[i], cont);
            } else {
                printf("\n> Número %d aparece %d vez", vet[i], cont);
            }
        }  
    }
}


void min_bills(int value, int n, int bills[]){
    int count[n];

    for (int i = 0; i < n; i++){
        count[i] = 0; //zerando todos os valores do vetor
    }

    for (int i = n - 1; i >= 0; i--){
        if (value >= bills[i]){
            count[i] = value / bills[i]; //calculando quantas cédulas são necessárias
            value = value % bills[i]; //atualiza o valor restante
        }
    }
    
    for (int i = n - 1; i >= 0; i--){
        if (count[i] > 0){
            printf("\n%d x R$%d,00", count[i], bills[i]);
        }
    }
}


void vector_union(int n1, int vet1[n1], int n2, int vet2[n2], int vet3[n1 + n2]){
    int k = 0;

    for (int i = 0; i < n1; i++){
        int repetido = 0;

        for (int j = 0; j < k; j++){
            if (vet1[i] == vet3[j]){
                repetido = 1;
                break;
            }
        }

        if (!repetido){
            vet3[k] = vet1[i];
            k++;
        }      
    }

    for (int i = 0; i < n2; i++){
        int repetido = 0;

        for (int j = 0; j < k; j++){
            if (vet2[i] == vet3[j]){
                repetido = 1;
                break;
            }
        }

        if (!repetido){
            vet3[k] = vet2[i];
            k++;
        }      
    }

    for (int i = k; i < (n1 + n2); i++){
        vet3[i] = 0;
    }
    
    printf("\nVetor 3 (união): ");
    for (int i = 0; i < (n1 + n2); i++){
        printf("%d ", vet3[i]);
    }
}


void vector_intersection(int n1, int vet1[n1], int n2, int vet2[n2], int vet3[]){
    int k = 0;

    for (int i = 0; (i < n1) && (i < n2); i++){
        vet3[i] = 0;
    }

    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            if (vet1[i] == vet2[j]){
                int repetido = 0;

                for (int x = 0; x < k; x++){
                    if (vet3[x] == vet1[i]){
                        repetido = 1;
                        break;
                    }
                }
            
                if (!repetido){
                    vet3[k] = vet1[i];
                    k++;
                }
                
                break;
            }  
        }
    } 

    printf("\nVetor 3 (interseção): ");
    for (int i = 0; i < k; i++){
        printf("%d ", vet3[i]);    
    }
}


int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);

        if (nEx == 1) {
            int n = 5;
            int vet[] = {3, 8, 5, 12, 7};

            printf("Vetor completo: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            printf("\nValores pares do vetor: ");
            print_even(n, vet);

            
        } else if (nEx == 2){
            int n = 8;
            int vet[] = {1, -5, 67, -45, -1, -1, 0, 48};

            printf("Vetor completo: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            printf("\nVetor positivo: ");
            set_positive(n, vet);
            
        } else if (nEx == 3){
            int n = 5;
            int vet[] = {3, 8, 5, 12, 7};

            printf("Vetor completo: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }

            find_max(n, vet);
            
        } else if (nEx == 4){
            int n = 8;
            int elem = 5;
            int vet[] = {1, 5, 3, 9, 5, 9, 10, 6};

            printf("Vetor completo: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            replace_all(n, vet, elem);
            
        } else if (nEx == 5){
            int n, i = 0;

            printf("Informe o tamanho do vetor: ");
            scanf("%d", &n);

            int vet[n];
            read_vector(n, vet);
            
        } else if (nEx == 6){
            int n = 5;
            int vet[] = {6, 5, 9, 12, 4};

            printf("Vetor completo: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            if (is_sorted(n, vet)){
                printf("\n- O vetor está ordenado.\n\n");
            } else {
                printf("\n- O vetor não está ordenado.\n\n");
            }
            
        } else if (nEx == 7){
            int n = 3;
            int points[] = {2, 3, 4, 9, 3, 7}; 

            printf("Vetor completo: ");
            for (int i = 0; i < n * 2; i++) {
                printf("%d ", points[i]);
            }

            printf("\n");
            distances(n, points);
            
        } else if (nEx == 8){
            int n = 5;
            int vet[] = {2, 3, 5, 9, 10};

            printf("Vetor original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            reverse(n, vet);

            printf("\nVetor invertido: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            printf("\n\n");
            
        } else if (nEx == 9){
            int n = 5;
            int vet1[] = {2, 6, 8, 10, 3};
            int vet2[] = {1, 4, 5, 7, 10};

            printf("Vetor 1 original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet1[i]);
            }

            printf("\nVetor 2 original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet2[i]);
            }
            
            vector_copy(n, vet1, vet2);

            printf("\n\n");
            
        } else if (nEx == 10){
            int n = 5;
            int elem = 0;
            int vet[] = {5, -1, 2, -1, 6};

            printf("Vetor original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }

            printf("\nVetor alterado: ");
            vector_insert(n, vet, elem);

            printf("\n\n");
            
        } else if (nEx == 11){
            int n = 5;
            int pos = 3; //posições {0, 1, 2, 3, 4} = (n = 5)
            int vet[] = {3, 0, 5, 9, 4};

            printf("Vetor original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            printf("\nVetor modificado: ");
            vector_remove(n, vet, pos);

            printf("\n\n");
            
        } else if (nEx == 12){
            int n = 5;
            int vet[] = {5, -1, 8, -1, 2};

            printf("Vetor original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            printf("\nVetor desfrangmentado: ");
            vector_defrag(n, vet);

            printf("\n\n");
            
        } else if (nEx == 13){
            int n1 = 4;
            int n2 = 6;
            int vet1[] = {1, 2, 3, 4};
            int vet2[] = {5, 6, 7, 8, 9, 10};
            int vet3[n1 + n2];

            printf("Vetor 1: ");
            for (int i = 0; i < n1; i++){
                printf("%d ", vet1[i]);
            }

            printf("\nVetor 2: ");
            for (int i = 0; i < n2; i++){
                printf("%d ", vet2[i]);
            }
            
            printf("\nVetor 3: ");
            vector_concat(n1, vet1, n2, vet2, vet3);

            printf("\n\n");
            
        } else if (nEx == 14){
            int n1 = 6;
            int n2 = 6;
            int vet1[] = {1, 3, 4, 7, 9, 10};
            int vet2[] = {2, 3, 5, 7, 7, 14};
            int vet3[n1 + n2];

            printf("Vetor 1: ");
            for (int i = 0; i < n1; i++){
                printf("%d ", vet1[i]);
            }

            printf("\nVetor 2: ");
            for (int i = 0; i < n2; i++){
                printf("%d ", vet2[i]);
            }
            
            printf("\nVetor 3 (mesclado): ");
            merge(n1, vet1, n2, vet2, vet3);

            printf("\n\n");
            
        } else if (nEx == 15){
            int n = 12;
            int vet[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};

            printf("Vetor original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }

            int result = max_num_slice2(n, vet);
            printf("\nO resultado da soma é: %d", result);

            printf("\n\n");
            
        } else if (nEx == 16){
            int n = 8;
            int vet[] = {0, 5, 5, 3, 1, 9, 4, 4};

            printf("Vetor original: ");
            for (int i = 0; i < n; i++){
                printf("%d ", vet[i]);
            }
            
            count_elements(n, vet);

            printf("\n\n");
            
        } else if (nEx == 17){
            int value = 346;
            int n = 5; //tamanho de bills
            int bills[] = {1, 5, 10, 50, 100};

            min_bills(value, n, bills);

            printf("\n\n");
            
        } else if (nEx == 18){
            int n1 = 5;
            int n2 = 3;
            int vet1[] = {1, 2, 3, 4, 5};
            int vet2[] = {2, 3, 8};
            int vet3[n1 + n2];

            printf("Vetor 1: ");
            for (int i = 0; i < n1; i++){
                printf("%d ", vet1[i]);
            }
            
            printf("\nVetor 2: ");
            for (int i = 0; i < n2; i++){
                printf("%d ", vet2[i]);
            }

            vector_union(n1, vet1, n2, vet2, vet3);

            printf("\n\n");
            
        } else if (nEx == 19){
            int n1 = 5;
            int n2 = 4;
            int vet1[] = {1, 2, 3, 4, 5};
            int vet2[] = {2, 3, 8, 5};
            int vet3[n1 + n2];

            printf("Vetor 1: ");
            for (int i = 0; i < n1; i++){
                printf("%d ", vet1[i]);
            }

            printf("\nVetor 2: ");
            for (int i = 0; i < n2; i++){
                printf("%d ", vet2[i]);
            }

            vector_intersection(n1, vet1, n2, vet2, vet3);

            printf("\n\n");
            
        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}