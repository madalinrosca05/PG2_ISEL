#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

/*
    3.4. Programa prog23
    Este programa lê um ficheiro de dados bibliográficos, armazena-os numa
    coleção e apresenta os dados armazenados no final.
*/

int main(int argc, char *argv[]) {
    // Verificar se o nome do ficheiro foi passado como argumento
    if (argc != 2) {
        fatal_error("Uso: ./prog23 <ficheiro_de_dados>\n");
    }

    // Criar uma coleção para armazenar os livros
    Collection my_collection = { .count = 0 };

    // Processar o ficheiro e preencher a coleção usando a função collAddBook
    int result = processFile(argv[1], collAddBook, &my_collection);

    // Verificar se houve erro no processamento do ficheiro
    if (result < 0) {
        fatal_error("Erro: Não foi possível processar o ficheiro de dados.\n");
    }

    // Apresentar os dados armazenados na coleção
    for (int i = 0; i < my_collection.count; i++) {
        BookData *b = &my_collection.books[i];
        printf("%s;%s;%s;%s\n", 
               b->title, 
               b->isbn, 
               b->authors, 
               b->publisher);
    }

    // Informação adicional útil (opcional)
    // printf("\nProcessamento concluído. Total de livros armazenados: %d\n", my_collection.count);

    return 0;
}