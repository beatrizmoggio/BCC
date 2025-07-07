#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int id;
    char name[51];
} Movie;


void print_array(int n, int* v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}


/*
1. Escreva uma função que grava o conteúdo de um vetor de inteiros em um arquivo. Caso o arquivo
não exista, a função deve criá-lo.
*/
void write_array(const char* filepath, const int* v, int n){
    FILE* file = fopen(filepath, "wb"); // abre o arquivo para escrita; cria se não existir

    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
    }

    fwrite(v, sizeof(int), n, file); // escreve n inteiro do vetor no arquivo
    fclose(file);
}


/*
2. Escreva uma função que lê o conteúdo de um arquivo para um vetor de inteiros, alocado em heap.
A função deve retornar o endereço do vetor alocado na heap. O tamanho do vetor deve ser
retornado pelo parâmetro 'n'. Caso o arquivo não exista, a função deve retornar NULL.
*/
int* read_array(const char* filepath, int* n){
    FILE* file = fopen(filepath, "rb"); // abre o arquivo para leitura
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    fseek(file, 0, SEEK_END); // move o cursor para o fim do arquivo
    *n = ftell(file) / sizeof(int); // calcula tam do arquivo em bytes
    rewind(file); // volta o cursor para o inicio do arquivo
    
    int* v = malloc(len * sizeof(int));
    fread(v, sizeof(int), *n, file); // lê os inteiros
    fclose(file);
    return v;
}


/*
3. Para os exercícios que seguem, considere o tipo estruturado Movie, que deverá ser utilizado para
manipular arquivos de registros de filmes:
*/
void write_all_movies(const char* filepath, const Movie* list, int n){
    FILE* file = fopen(filepath, "wb"); // abre o arquivo para escrita; cria se não existir
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
    }
    
    fwrite(list, sizeof(Movie), n, file); // grava os registros
    fclose(file);
}


/*
4. Escreva uma função que retorna a quantidade de registros de filmes contidos em um arquivo.
*/
int count_movies(const char* filepath) {
    FILE* file = fopen(filepath, "rb"); // abre o arquivo para leitura
    if (file == NULL) {
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    fseek(file, 0, SEEK_END); // move o cursor para o fim do arquivo
    int count = ftell(file) / sizeof(Movie); // calcula a quantidade de registros
    fclose(file);
    return count;
}


/*
5. Escreva uma função que lê um registro de filme de um arquivo, na posição indicada (0, 1, 2, …). A
função deve retornar uma cópia do registro. Se a posição for inválida, a função deve retornar um
registro preenchido com zeros. OBS: você não deve trazer todos os registros para a RAM, em um
array. A função deve ler somente somente o registro em questão.
*/
Movie read_movie(const char* filepath, int pos) {
    Movie m = {0}; // inicializa os registros com zeros
    FILE* file = fopen(filepath, "rb"); // abre o arquivo para leitura
    if (file == NULL) {
        printf("ERRO: arquivo não existe.\n");
        return m;
    }
    
    fseek(file, pos * sizeof(Movie), SEEK_SET); // posiciona o cursor na posição do registro
    fread(&m, sizeof(Movie), 1, file); // lê o registro do arquivo para m
    fclose(file);
    return m;
}


/*
6. Escreva uma função que retorna a posição de um registro de filme em um arquivo, a partir de seu
ID (campo Movie::id). A função deve retornar a posição (índice) que o registro ocupa no arquivo ou
-1, caso ID inexistente. OBS: você não deve trazer todos os registros para a RAM, em um array. A
função deve acessar registro por registro, no próprio arquivo.
*/
int find_movie(const char* filepath, long id) {
    FILE* file = fopen(filepath, "rb"); // abre para leitura
    if (file == NULL) {
        printf("ERRO: arquivo não existe.\n");
        return -1;
    }
    
    Movie m; // armazena cada registro lido
    int pos = 0; // posição atual do registro
    
    while (fread(&m, sizeof(Movie), 1, file) == 1) { // le filme por filme
        if (m.id == id) { // se o id do registro for igual ao buscado:
            fclose(file); // fecha o arquivo
            return pos; // retorna a posição
        }

        pos++; // se não encontrar, incrementa pos e compara novamente
    }
    
    fclose(file);
    return -1; // nao encontrado
}


/*
7. Escreva uma função que adiciona um registro ao final de um arquivo de filmes. A função deve
retornar 1 (true) para sucesso ou 0 (false) em caso de erro. OBS: você não deve trazer todos os
registros para a RAM, em um array.
*/
int add_movie(const char* filepath, const Movie* movie) {
    FILE* file = fopen(filepath, "ab"); // abre o arquivo para escrita (add) - fim do arquivo
    if (file == NULL) {
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    int ok = fwrite(movie, sizeof(Movie), 1, file); // escreve novo registro no fim do arquivo
    fclose(file);
    return ok == 1; // sucesso
}


/*
8. Escreva uma função que grava um registro em um arquivo de filmes a partir de seu ID (Movie::id),
substituindo o existente. A função deve retornar 1 (true) para sucesso ou 0 (false), em caso de erro
ou ID inexistente. OBS: você não deve trazer todos os registros para a RAM, em um array. A
função deve acessar somente o registro especificado.
*/
int update_movie(const char* filepath, const Movie* movie) {
    FILE* file = fopen(filepath, "rb+"); // abre o arquivo para leitura e escrita
    if (file == NULL) {
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }

    Movie m;
    while (fread(&m, sizeof(Movie), 1, file) == 1) { // lê registro por registro
        if (m.id == movie->id) { // compara id do registro atual com o do filme a atualizar
            fseek(file, -sizeof(Movie), SEEK_CUR); // volta o cursor para o inicio do registro atual
            fwrite(movie, sizeof(Movie), 1, file); // escreve o novo registro
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}


/*
9. Escreva uma função que remove um registro em um arquivo de filmes, a partir de seu ID
(Movie::id). A função não apaga os dados do registro, mas apenas marca-o como removido,
definindo ID = -1. A função deve retornar 1 (true) para sucesso ou 0 (false) em caso de erro. OBS:
você não deve trazer todos os registros para a RAM, em um array. A função deve acessar somente
o registro especificado.
*/
int delete_movie(const char* filepath, long id) {
    FILE* file = fopen(filepath, "rb+"); // abre o arquivo para leitura e escrita
    if (file == NULL) {
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    Movie m;
    while (fread(&m, sizeof(Movie), 1, file) == 1) { // lê registro por registro
        if (m.id == id) {
            m.id = -1; // se achar o registro, muda o id para -1 para marcar como removido
            fseek(file, -sizeof(Movie), SEEK_CUR); // volta o cursor para o inicio do arquivo
            fwrite(&m, sizeof(Movie), 1, file); // sobrescreve com o registro modificado (id = -1)
            fclose(file);
            return 1;
        }
    }
    
    fclose(file);
    return 0;
}


/*
10. Escreva uma função que adiciona um registro em um registro em um arquivo de filmes, de forma
ordenada crescente, a partir de seu ID (Movie::id). A função deve retornar 1 (true) para sucesso ou
0 (false) em caso de erro. Note que será necessário "reposicionar" os registros no arquivo, de
forma a permitir a inserção de um novo registro na posição correta. OBS: para que o arquivo tenha
todos os registros em ordem crescente de ID, é preciso inseri-los gradativamente com esta função.
OBS: você não deve trazer todos os registros para a RAM, em um array. A função deve acessar
registro por registro, no próprio arquivo.
*/
int insert_sorted(const char* filepath, const Movie* movie) {
    FILE* file = fopen(filepath, "rb"); // abre o arquivo original para leitura
    FILE* temp = fopen("dados/temp.bin", "wb"); // cria arquivo temporario para escrita
    
    if (temp == NULL) {
        printf("ERRO: não foi possível abrir/criar o arquivo.\n");
        return 0;
    }
    
    int inserido = 0; // indica se o novo filme ja foi inserido
    Movie m;
    
    if (file != NULL) {
        while (fread(&m, sizeof(Movie), 1, file) == 1) { // lê registro por registro
            if (!inserido && movie->id < m.id) { // se ainda não inseriu o novo filme e o id dele é menor que o do filme atual
                fwrite(movie, sizeof(Movie), 1, temp); // insere o novo filme no arquivo temp antes do filme atual
                inserido = 1; // marca como inserido
            }
            
            fwrite(&m, sizeof(Movie), 1, temp); // escreve o filme atual do arquivo original para o temp
        }
        
        fclose(file);
    }
    
    if (!inserido) fwrite(movie, sizeof(Movie), 1, temp); // se nao inseriu ainda, escreve no final
    fclose(temp);
    remove(filepath); // remove antigo
    rename("dados/temp.bin", filepath); // renomeia
    return 1;
}

/*
11. Considere o seguinte cenário: após a realização de várias remoções com a função delete_movie(),
o arquivo ficará repleto de "buracos" (registros marcados com ID = -1). Escreva uma função que
desfragmenta o arquivo, deixando todos os registros válidos de forma consecutiva, a partir do início
do arquivo. OBS: você não deve trazer todos os registros para a RAM, em um array. A função deve
acessar registro por registro, no próprio arquivo. A função deve retornar 1 (true) para sucesso ou 0
(false) em caso de erro.
*/
int defrag(const char* filepath) {
    FILE* file = fopen(filepath, "rb"); // abre o arquivo original para leitura
    FILE* temp = fopen("dados/temp.bin", "wb"); // cria arquivo temporario para escrita

    if (file == NULL || temp == NULL) {
        printf("ERRO: não foi possível abrir/criar o arquivo.\n");
        return 0;
    }

    Movie m;
    while (fread(&m, sizeof(Movie), 1, file) == 1) {
        if (m.id != -1) fwrite(&m, sizeof(Movie), 1, temp); // apenas registros validos
    }

    fclose(file);
    fclose(temp);
    remove(filepath);
    rename("dados/temp.bin", filepath);
    return 1;
}



int main(){
    int nEx = -1;
    
    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);
        
        if (nEx == 1) {
            int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            write_array("dados/dados.bin", v, 10);
            printf("Arquivo criado com sucesso!\n");
            printf("\n");
    
        } else if (nEx == 2) {
            int n;
            int* v = read_array("dados/dados.bin", &n);
            print_array(n, v);
            free(v);
            printf("\n");
    
        } else if (nEx == 3) {
            Movie list[] = {
                {6, "They Live"},
                {11,"Big Trouble in Little China"},
                {10,"The Thing"},
                {1, "In the Mouth of Madness"},
                {8, "Ghosts of Mars"},
                {23,"Halloween"},
                {7, "Village of the Damned"}
            };

            // cria arquivo 'dados.bin' com conteúdo de 'list'
            write_all_movies("movies.bin", list, 7);
            printf("\n");
    
        } else if (nEx == 4) {
            // considerando o exemplo do exercício anterior
            int size = count_movies("movies.bin"); // size = 7
            printf("\n");
    
        } else if (nEx == 5) {
            
            printf("\n");
    
        } else if (nEx == 6) {
            
            printf("\n");
    
        } else if (nEx == 7) {
            
            printf("\n");
    
        } else if (nEx == 8) {
            
            printf("\n");
    
        } else if (nEx == 9) {
            
            printf("\n");
    
        } else if (nEx == 10) {
            
            printf("\n");
                
        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}