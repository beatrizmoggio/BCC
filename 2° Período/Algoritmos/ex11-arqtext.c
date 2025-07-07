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
1. Escreva uma função que verifica se o arquivo de caminho informado existe (retorna 1). Caso
contrário, retorna 0.
*/
int file_exists(const char* filepath){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leitura

    if (file == NULL) { // verifica se existe
        printf("ERRO: arquivo não existe.\n");
        return 0;
    } else {
        fclose(file);
        return 1;
    }
}


/*
2. Escreva uma função que receba um caminho de arquivo. Se o mesmo existir, faz nada. Se o
arquivo não existir, tenta criá-lo. A função deve retornar 1 (um) caso arquivo exista ou tenha sido
criado e, 0 (zero), caso contrário.
*/
int check_or_create(const char *filepath){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leitura
    if (file != NULL) { // se o arquivo existir
        printf("O arquivo existe.\n"); // faz nada
        fclose(file);
        return 1;
    }
    
    // se não existir
    file = fopen(filepath, "w"); // cria o arquivo
    if (file == NULL){
        printf("ERRO: falha ao criar o arquivo.\n");
        return 0;
    }
    
    printf("Arquivo criado com sucesso!\n");
    fclose(file);
    return 1;    
}


/*
3. Escreva uma função que receba um caminho de arquivo e imprima seu conteúdo no terminal.
Retorna 1 para sucesso ou 0, caso o arquivo não exista.
*/
int print_content(const char *filepath){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leirua
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }

    char c = fgetc(file); // lê o primeiro caractere
    while (c != EOF) { // enquanto não chegar no fim do arquivo
        printf("%c", c); // imprime o caractere lido
        c = fgetc(file); // lê o próximo caractere
    }
    
    fclose(file);
    return 1;
}


/*
4. Escreva uma função que receba um caminho de arquivo e escreva uma string no mesmo. A função
deve (re)criar o arquivo especificado. Retorna 1 para sucesso ou 0, em caso de erro.
*/
int save_string(const char *filepath, const char* text){
    FILE* file = fopen(filepath, "w"); // abre o arquivo para escrita; cria se não existir
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    int res = fputs(text, file); // adiciona a string no arquivo
    if (res == EOF){
        printf("Erro ao escrever no arquivo.\n");
        fclose(file);
        return 0;
    }
    
    printf("Função realizada com sucesso!\n");
    fclose(file);
    return 1;
}


/*
5. Escreva uma função que receba um caminho de arquivo e adicione uma string no mesmo. A função
deve criar o arquivo especificado, caso não exista. Retorna 1 para sucesso ou 0, em caso de erro.
Dica: observe o modo de abertura 'a' (slide no. 5 do material).
*/
int append_string(const char *filepath, const char* text){
    FILE* file = fopen(filepath, "a"); // abre o arquivo para escrita com o cursor no fim
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    int res = fputs(text, file); // adiciona o texto no fim do arquivo
    if (res == EOF){
        printf("Erro ao escrever no arquivo.\n");
        fclose(file);
        return 0;
    }
    
    printf("Função realizada com sucesso!\n");
    fclose(file);
    return 1;
}


/*
6. Escreva uma função que receba um caminho de arquivo e escreva linhas de strings no mesmo. Ela
deve (re)criar o arquivo especificado. A função recebe um vetor de strings e cada uma deve ser
escrita em uma linha do arquivo. Retorna 1 para sucesso ou 0, em caso de erro.
*/
int save_lines(const char *filepath, int n, const char text_lines[n][51]){
    FILE* file = fopen(filepath, "w"); // abre o arquivo para escrita; cria se não existir
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    int res = 0; // guarda o result da última escrita
    for (int i = 0; i < n; i++){ // para cada string do vetor
        res = fputs(text_lines[i], file); // escreve a linha no arquivo
        fputs("\n", file); // adiciona a quebra de linha
    }
    
    if (res == EOF){
        printf("Erro ao escrever no arquivo.\n");
        fclose(file);
        return 0;
    }
    
    printf("Função realizada com sucesso!\n");
    fclose(file);
    return 1;
}


/*
7. Escreva uma função que receba um caminho de arquivo e retorna uma string alocada em heap
contendo o conteúdo do arquivo. Caso ocorra algum problema, retorna NULL.
*/
char* get_content(const char *filepath){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leitura
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    fseek(file, 0, SEEK_END); // move o cursor para o fim do arquivo
    int len = ftell(file)/sizeof(char); // tam total do arquivo em bytes
    fseek(file, 0, SEEK_SET); // volta o cursor para o inicio do arquivo

    char* str = malloc((len + 1) * sizeof(char));
    if (str == NULL) {
        printf("Erro ao alocar na memória.\n");
        return NULL;
    }

    int i = 0;
    char c = fgetc(file); // lê o primeiro caractere
    while (c != EOF){ // enquanto não chegar no fim do arquivo
        str[i] = c; // armazena cada caractere em str[i]
        c = fgetc(file); // lê o próximo caractere
        i++; // incrementa i - posição do str
    }

    str[len] = '\0'; // finaliza a string com caractere nulo
    fclose(file);
    return str;
}


/*
8. Escreva uma função que retorna a posição de um ou mais caracteres dentro do arquivo, a partir da
posição informada. Caso não encontre um dos caracteres procurados, a função deve retornar -1.
Note que a função espera receber um ponteiro de arquivo já aberto (FILE*). OBS: Esta é uma
função utilitária para a lista de exercícios e poderá ser usada para ajudar a resolver outros
problemas, incluindo: contar número de palavras, linhas, encontrar início de final de palavras (são
envoltas por determinados caracteres).
*/
int find(FILE* file, const char* ch, int whence){
    if (file == NULL || ch == NULL){ // verifica se o arquivo ou string são nulos
        return -1;
    }

    fseek(file, whence, SEEK_SET); // posiciona o cursos na pos
    int pos = whence; // armazena o indice atual da pos
    int c = fgetc(file); // lê o primeiro caractere

    while (c != EOF){ // enquanto não chegar no fim do arquivo
        for (int i = 0; ch[i] != '\0'; i++){ // para cada caractere de ch
            if (c == ch[i]){ // verifica se c = ch[i]
                return pos; // se sim, retorna sua posição
            }
        }

        pos++; // se não, incrementa pos e
        c = fgetc(file); // lê o próximo caractere
    }
    
    return -1;
}


/*
9. Escreva uma função que receba um caminho de arquivo e retorna a quantidade de linhas de texto
contidas no arquivo. Dica: o caractere '\n' define a quebra de linha no texto. Utilize a função find()
do exercício 4 para facilitar a implementação.
*/
int count_lines(const char *filepath){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leitura
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }

    int pos = 0; // inicializa a pos
    int linhas = 0; // inicializa o contador de linhas

    pos = find(file, "\n", pos); // encontra a primeira quebra de linha com a função find()
    while (pos != -1){ // enquanto encontrar quebra de linha ('\n')
        linhas++; // conta a linha
        pos = find(file, "\n", pos + 1); // procura a próxima quebra de linha
    }

    fclose(file);
    return linhas;
}


/*
10. Escreva uma função que receba um caminho de arquivo e retorna a quantidade de palavras
contidas no arquivo. As palavras estão separadas por espaço(s), virgula (,) ou linha (\n). Utilize a
função find() do exercício 4 para facilitar a implementação. Dica: se uma busca consecutiva pelos
separadores mencionados " ,\n" retornar posições não consecutivas, isto é, pos2 > pos1 + 1, então
você encontrou uma palavra, pois existe algo que não é um separador entre pos1 e pos2.
*/
int count_words(const char *filepath){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leitura
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }
    
    int cont = 0; // armazena a quantidade de palavras lidas
    int pos1 = 0, pos2 = 0; // posições no arquivo para delimitar trechos entre separadores (" ", ", ", "\n" == " ,\n")

    pos1 = find(file, " ,\n", 0); // procura o primeiro caractere separador a partir da pos 0

    if (pos == -1){ // se não encontrou nenhum separador
        fclose(file);
        return 0;
    }
    
    pos2 = find(file, " ,\n", (pos + 1)); // encontra o próximo separador

    while (pos != -1){ // enquanto encontrar separadores
        if (pos2 > (pos1 + 1)){ // se a distancia entre pos1 e pos2 for maior que 1
            cont++; // existe uma palavra = conta uma palavra
        }

        pos1 = pos2; // move pos1 para o separador atual
        pos2 = find(file, " ,\n", (pos1 + 1)); // busca o próximo separador
    }
    
    fclose(file);
    return cont;
}


/*
11. Escreva uma função que receba um caminho de arquivo e preenche um vetor de strings (words)
com todas as palavras encontradas. As palavras estão, necessariamente, separadas por
espaço(s), virgula (,) ou nova linha (\n). OBS: Considere que o array de strings tem tamanho
suficiente para receber todas as palavras do arquivo. Esta função também pode ser útil para ajudar
a resolver vários outros exercícios desta lista.
*/
void get_words(const char *filepath, int n, words[n][51]){
    FILE* file = fopen(filepath, "r"); // abre o arquivo para leitura
    if (file == NULL){
        printf("ERRO: arquivo não existe.\n");
        return 0;
    }

    int i = 0; // indice da palavra do vetor words
    int j = 0; // indice do caractere dentro da palavra atual

    char c = fgetc(file); // lê o primeiro caractere
    while (c != EOF){ // enquanto não chegar ao fim do arquivo{
        if (c == ' ' || c == ',' || c == '\n'){ // verifica se o caractere lido é um separador de palavras
            if (j > 0){ // uma palavra esta sendo formada
                words[i][j] = '\0'; // finaliza a palavra
                i++; // passa para a próxima palavra
                j = 0; // reinicia a próxima palavra
            
            } else{
                words[i][j++] = c; // se não é separados, add o caractere à palavra atual
            }
            
            c = fgetc(file); // lê o próximo caractere
        }
    
        if (j > 0){ // última palavra
            words[i][j] = '\0';
        }
    }

    fclose(file);
}


/*
12. Escreva uma função que receba um caminho de arquivo com texto organizado em linhas
(separador '\n'). A função deve criar arquivos separados, contendo cada uma das linhas de texto do
arquivo original. Os arquivos devem ser nomeados "lineX.txt", onde X é um contador incremental
que inicia em 1. A função deve retornar 1 para sucesso ou 0 para falhar. Dica: utilize fgets() e
fputs(). Utilize a função sprintf() para gerar os nomes dos arquivos facilmente. Veja:
https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
*/
int split_lines(const char *filepath){

}


/*
13. Escreva uma função que imprime a contagem de palavras por quantidade de letras, de um arquivo.
A contagem deve ser informada em ordem crescente de quantidade de letras.
*/
void report_by_chars(const char* filepath){

}


/*
14. Escreva uma função que conta todas as ocorrências de uma dada palavra, em um arquivo.
*/
int word_frequency(const char* filepath, const char* word){
    int n = count_words(filepath); // conta quantas palavras existem no arquivo
    if (n == 0){
        printf("Não existe nenhuma palavra.");
        return 0;
    }
    
    char words[n][51]; // armazena as palavras do arquivo
    get_words(filepath, n, words); // preenche words com as palavras do arquivo

    int cont = 0; // inicializa contador de palavras
    for (int i = 0; i < n; i++){ // percorre todas as palavras do arquivo
        if (strcmp(words[i], word) == 0){ // compara a palavra atual com a palavra buscada
            cont++; // se for igual a 0 significa que é igual, logo, incrementa o contador
        }
    }
    
    return cont;
}


/*
15. Escreva uma função que imprime as ocorrências de todas as palavras, em um arquivo. As palavras
estão separadas por, pelo menos, um espaço. Dica: você vai precisar criar alguma "tabela" de
contagem, que permite armazenar uma palavra e sua contagem.
*/
int words_report(const char* filepath, const char* word){

}


/*
16. Escreva uma função que retorna o endereço de um vetor em heap, contendo a palavra de maior
comprimento em um arquivo. Nesse arquivo, as palavras estão separadas por, pelo menos, um
espaço. Caso ocorra algum problema, retorna NULL.
*/
char* get_longest(const char *filepath){

}


/*
17. Escreva uma função que substitui todas as ocorrências de uma dada palavra por outra, em um
arquivo. A função deve retornar a quantidade de substituições realizadas.
*/
int replace_word(const char* filepath, const char* old, const char* new){

}


int main(){
    int nEx = -1;

    while (nEx != 0){
        printf("Escolha o número do exercício (0 p/ sair): > ");
        scanf("%d", &nEx);
    
        if (nEx == 1) {
            int res = file_exists("arquivos/arquivo1.txt");
            printf("Arquivo existe? %d\n", res);
            printf("\n");
        
        } else if (nEx == 2) {
            const char* path = "arquivos/arquivo2.txt";
            check_or_create(path);
        
            printf("\n");
        
        } else if (nEx == 3) {
            const char* path = "arquivos/arquivo3.txt";
            print_content(path);
        
            printf("\n\n");
        
        } else if (nEx == 4) {
            const char *filepath = "arquivos/arquivo4.txt";
            const char* text = "Universidade Tecnológica";
            save_string(filepath, text);
        
            printf("\n");
        
        } else if (nEx == 5) {
            const char *filepath = "arquivos/arquivo5.txt";
            const char* text = "Universidade ";
            append_string(filepath, text);
        
            printf("\n");
        
        } else if (nEx == 6) {
            const char* filepath = "arquivos/arquivo6.txt";
            const char text_lines[5][51] = {
                "Primeira linha",
                "Segunda linha",
                "Terceira linha",
                "Quarta linha",
                "Quinta linha"
            };

            save_lines(filepath, 5, text_lines);
        
            printf("\n");
        
        } else if (nEx == 7) {
            const char* filepath = "arquivos/arquivo7.txt";
            char* str = get_content(filepath);

            if (str != NULL){
                printf("%s\n", str);
                free(str);    
            } else {
                printf("Erro ao ler conteúdo do arquivo.\n");
            }
        
            printf("\n");
        
        } else if (nEx == 8) {
            FILE* file = fopen("arquivos/arquivo8.txt", "r");
            if (file == NULL){
                printf("ERRO: arquivo não existe.\n");
                return 1;
            }

            int pos = find(file, ".", 0);
            if (pos != -1){
                printf("Caractere '.' encontrado na posição: %d\n", pos);
            } else {
                printf("Caractere '.' não encontrado!");
            }
            
            fclose(file);
            printf("\n");

            // ta retornando número a mais
        } else if (nEx == 9) {
            const char* filepath = "arquivos/arquivo9.txt";
            int linhas = count_lines(filepath);
            printf("Número de linhas: %d\n", linhas);
            
            printf("\n");

        } else if (nEx == 10) {
            const char* filepath = "arquivos/arquivo9.txt";
            int linhas = count_lines(filepath);
            printf("Número de linhas: %d\n", linhas);
            
            printf("\n");
        
        } else if (nEx == 0){
            printf("<<< Programa finalizado >>>\n\n");

        } else if (nEx != 0){
            printf("Opção inválida. Tente novamente!\n\n");
        }
    }

    return 0;
}