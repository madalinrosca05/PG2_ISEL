#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

// Função local que garante a ordenação antes de imprimir os livros.
void listBooks(Collection *col) {
    // Garante que a lista está alfabética antes de mostrar ao utilizador.
    collSortTitle(col); 
    for (int i = 0; i < col->count; i++) {
        BookData *b = &col->books[i];
        printf("%s; %s; %s; %s\n", 
               b->title, b->authors, b->publisher, b->isbn);
    }
}

int main(int argc, char *argv[]) {
    // Garante que temos o ficheiro necessário para trabalhar.
    if (argc != 2) {
        fatal_error("Uso: ./prog24 <ficheiro_de_dados>\n");
    }

    Collection col = { .count = 0 };
    // Lê o ficheiro e preenche a coleção.
    if (processFile(argv[1], collAddBook, &col) < 0) {
        fatal_error("Erro ao processar ficheiro.\n");
    }
    
    // Loop de comando para listar livros ou sair do programa.
    char command;
    while (printf("> "), scanf(" %c", &command) == 1) {
        if (command == 'q') break;
        
        if (command == 'l') {
            listBooks(&col); 
        } else {
            printf("Comando desconhecido: %c\n", command);
        }
    }

    return 0;
}