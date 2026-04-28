#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

// Lê um ficheiro de dados bibliográficos, armazena-os numa coleção e apresenta os dados armazenados no final.
int main(int argc, char *argv[]) {
    // Verifica se o nome do ficheiro foi passado como argumento.
    if (argc != 2) {
        fatal_error("Uso: ./prog23 <ficheiro_de_dados>\n");
    }

   // Inicializo a coleção com count = 0. 
    // É fundamental garantir que o contador começa a zero para não haver problemas no preenchimento do array.
    Collection my_collection = { .count = 0 };

    // Processar o ficheiro e preencher a coleção usando a função collAddBook
    int result = processFile(argv[1], collAddBook, &my_collection);

    // Verificar se houve erro no processamento do ficheiro
    if (result < 0) {
        fatal_error("Erro: Não foi possível processar o ficheiro de dados.\n");
    }

    // Apresentar os dados armazenados na coleção.
    for (int i = 0; i < my_collection.count; i++) {
        // Uso um ponteiro auxiliar para facilitar a leitura dos campos do livro.
        BookData *b = &my_collection.books[i];
        // Imprime os dados do livro no formato solicitado. 
        printf("%s;%s;%s;%s\n", 
               b->title, 
               b->isbn, 
               b->authors, 
               b->publisher);
    }

    return 0;
}