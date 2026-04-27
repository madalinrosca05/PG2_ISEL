#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fatal_error("Uso: ./prog25 <ficheiro_de_dados>\n");
    }

    Collection col = { .count = 0 };
    if (processFile(argv[1], collAddBook, &col) < 0) {
        fatal_error("Erro ao processar ficheiro.\n");
    }
    
    // Ordena a base de dados principal por título
    collSortTitle(&col);

    // Prepara o índice por ISBN logo no início (como pedido no 5.1)
    collSortRefIsbn(&col);

    char command;
    char isbn_search[SIZE_ISBN];

    printf("> ");
    while (scanf(" %c", &command) == 1 && command != 'q') {
        switch (command) {
            case 'l':
                listBooks(&col);
                break;

            case 'i':
                // Lê o ISBN que vem a seguir ao comando 'i'
                if (scanf("%s", isbn_search) == 1) {
                    BookData *found = collSearchIsbn(&col, isbn_search);
                    if (found != NULL) {
                        printf("%s; %s; %s; %s\n", 
                               found->title, found->authors, found->publisher, found->isbn);
                    } else {
                        printf("Aviso: Livro com ISBN %s nao encontrado.\n", isbn_search);
                    }
                }
                break;

            default:
                printf("Comando desconhecido: %c\n", command);
                // Limpar o resto da linha em caso de erro para não corromper o próximo comando
                while (getchar() != '\n'); 
                break;
        }
        printf("> ");
    }
    return 0;
}