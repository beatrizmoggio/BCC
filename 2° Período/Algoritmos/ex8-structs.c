#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


struct point {
    float x;
    float y;
};
typedef struct point Point;


void print_point(Point p){
    printf("Ponto: (%.2f, %.2f)\n", p.x, p.y);
}


float distance2D(Point p1, Point p2){
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    float dist = sqrt((dx*dx) + (dy*dy));
    return dist;
}


void distance_vector(int n, Point v[]){
    for (int i = 0; i < n - 1; i++){
        float dx = v[i + 1].x - v[i].x;
        float dy = v[i + 1].y - v[i].y;
        float dist = sqrt((dx*dx) + (dy*dy));
        printf("Distância entre ponto %d e ponto %d: %.2f\n", i, i + 1, dist);
    }
    printf("\n");
}


void random_points(int n, Point v[]){
    for (int i = 0; i < n; i++){
        float rx = rand() / (float)RAND_MAX * 100.0f - 50.0f;
        float ry = rand() / (float)RAND_MAX * 100.0f - 50.0f;

        v[i].x = rx;
        v[i].y = ry;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Ponto %d: (%.2f, %.2f)\n", i, v[i].x, v[i].y);
    }
}


void nearest_points(int n, Point v[]){
    float menorDist = 999999999.0f;
    int p1 = 0, p2 = 1;

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            float dx = v[j].x - v[i].x;
            float dy = v[j].y - v[i].y;
            float dist = sqrtf(dx*dx + dy*dy);

            if (dist < menorDist && dist > 0){
                menorDist = dist;
                p1 = i;
                p2 = j;
            }
        }
    }

    printf("A menor distância está entre os pontos p(%.2f, %.2f) e p(%.2f, %.2f) = %.4f\n", v[p1].x, v[p1].y, v[p2].x, v[p2].y, menorDist);
    printf("\n");
}


struct contact {
    int id;
    char name[51];
    char email[51];
    int type;
};
typedef struct contact Contact;


//Contact c = {1, "John Doe", "john.doe@email.com", 3};
void print_contact(Contact c, int n, char type_names[n][50]){
    printf("{%d, %s, %s, %s}\n\n", c.id, c.name, c.email, type_names[c.type]);
}


void print_contact_list(int n1, Contact list[n1], int n2, char types[n2][50]){
    
}


struct employee {
    char name[50];
    float salary;
    int type;  // 0 - Developer, 1 - Designer, 2 - Manager, 3 - Support
};
typedef struct employee Employee;


void print_best3(int n, Employee v[n]){
    float maior1 = -1, maior2 = -1, maior3 = -1;
    char nome1[50] = "", nome2[50] = "", nome3[50] = "";

    for (int i = 0; i < n; i++){
        float salarioAtual = v[i].salary; //salário do empregado atual
        char nomeAtual[50]; //nome do empregado atual
        strcpy(nomeAtual, v[i].name);

        if (salarioAtual > maior1){
            maior3 = maior2;
            strcpy(nome3, nome2);

            maior2 = maior1;
            strcpy(nome2, nome1);

            maior1 = salarioAtual;
            strcpy(nome1, nomeAtual);
        
        } else if (salarioAtual > maior2){
            maior3 = maior2;
            strcpy(nome3, nome2);

            maior2 = salarioAtual;
            strcpy(nome2, nomeAtual);

        } else if (salarioAtual > maior3){
            maior3 = salarioAtual;
            strcpy(nome3, nomeAtual);
        }      
    }

    printf("Top 3 salários:\n");
    printf("1. %s (R$%.2f)\n", nome1, maior1);
    printf("2. %s (R$%.2f)\n", nome2, maior2);
    printf("3. %s (R$%.2f)\n\n", nome3, maior3);
}


int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);

        if (nEx == 1) {
            Point p = {1.2345, 6.7890};
            print_point(p);
            printf("\n");


        } else if (nEx == 2) {
            Point p1 = {-2.0f, 7.5f};
            Point p2 = {5.0f, 12.4f};
            float dist = distance2D(p1, p2);
            printf("A distância entre p1(%.2f, %.2f) e p2(%.2f, %.2f) é: %.2f\n\n", p1.x, p1.y, p2.x, p2.y, dist);


        } else if (nEx == 3) {
            Point caminho[3] = {
                {0, 0},
                {3, 4},
                {6, 8}
            };

            distance_vector(3, caminho);


        } else if (nEx == 4) {
            int n = 3;
            Point vetor[n];

            random_points(n, vetor);
            printf("\n");


        } else if (nEx == 5) {
            Point vetor[3] = {
                {2, 6},
                {5, -2},
                {4, 4}
            };

            nearest_points(3, vetor);


        } else if (nEx == 6) {
            char types[5][50] = {"Família","Amigos","Trabalho","Escola","Outros"};
            Contact c = {1, "John Doe", "john.doe@email.com", 3};
            print_contact(c, 5, types);


        } else if (nEx == 7) {
            char types[][50] = {"Família","Amigo","Trabalho","Escola","Outros"};
            Contact list[] = {
                {1, "Marcus Fenix", "fenix@gow.com", 2},
                {41,"Blue Mary", "mary@ff3snk.net", 0},
                {17,"Barry Burton", "bburton@re.cap", 0},
                {8, "Charlie Nash", "nash@ssz.com", 2},
                {2, "Ada Wong", "wong@re2.net", 4},
                {5, "Chris Redfield", "crfield@re.cap", 0}
            };
            print_contact_list(6, list, 5, types);


        } else if (nEx == 8) {
            Employee empregados[5] = {
                {"Alice", 8500.50, 0},
                {"Bob", 2000.00, 1},
                {"Carol", 3900.75, 2},
                {"David", 5200.00, 3},
                {"Eve", 3200.00, 0}
            };
            print_best3(5, empregados);


        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}