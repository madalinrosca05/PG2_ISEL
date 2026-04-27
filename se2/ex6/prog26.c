#include <stdio.h>
#include <string.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fatal_error("Uso: ./prog26 <ficheiro_de_dados>\n");
    }

    Collection col = { .count = 0 };
    if (processFile(argv[1], collAddBook, &col) < 0) {
        fatal_error("Erro ao processar ficheiro.\n");
    }
    
    // Ordenações iniciais necessárias
    collSortTitle(&col);
    collSortRefIsbn(&col);

    char command;
    char search_buffer[128]; // Para ISBN ou nome de autor

    printf("> ");
    while (scanf(" %c", &command) == 1 && command != 'q') {
        switch (command) {
            case 'l':
                listBooks(&col);
                break;

            case 'i':
                if (scanf("%s", search_buffer) == 1) {
                    BookData *found = collSearchIsbn(&col, search_buffer);
                    if (found) {
                        printf("%s; %s; %s; %s\n", 
                               found->title, found->authors, found->publisher, found->isbn);
                    } else {
                        printf("Aviso: Livro com ISBN %s nao encontrado.\n", search_buffer);
                    }
                }
                break;

            case 'a':
                if (scanf("%s", search_buffer) == 1) {
                    // Percorre os dados na ordem alfabética de título
                    for (int i = 0; i < col.count; i++) {
                        if (bookContainsAuthor(&col.books[i], search_buffer)) {
                            BookData *b = &col.books[i];
                            printf("%s; %s; %s; %s\n", 
                                   b->title, b->authors, b->publisher, b->isbn);
                        }
                    }
                }
                break;

            default:
                printf("Comando desconhecido: %c\n", command);
                while (getchar() != '\n'); 
                break;
        }
        printf("> ");
    }
    return 0;
}