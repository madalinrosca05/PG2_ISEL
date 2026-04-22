#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

void listBooks(Collection *col) {
    collSortTitle(col); 
    for (int i = 0; i < col->count; i++) {
        BookData *b = &col->books[i];
        printf("%s; %s; %s; %s\n", 
               b->title, b->authors, b->publisher, b->isbn);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fatal_error("Uso: ./prog24 <ficheiro_de_dados>\n");
    }

    Collection col = { .count = 0 };
    if (processFile(argv[1], collAddBook, &col) < 0) {
        fatal_error("Erro ao processar ficheiro.\n");
    }

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