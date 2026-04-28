#include <stdio.h>
#include "book.h"
#include "processFile.h"
#include "errors.h"

// Função principal que gere a base de dados de livros e permite pesquisas por ISBN.
int main(int argc, char *argv[]) {
    // Verifica se o utilizador passou o ficheiro CSV como argumento.
    if (argc != 2) {
        fatal_error("Uso: ./prog25 <ficheiro_de_dados>\n");
    }

    Collection col = { .count = 0 };
    // Carrega os dados do ficheiro para a nossa estrutura na memória.
    if (processFile(argv[1], collAddBook, &col) < 0) {
        fatal_error("Erro ao processar ficheiro.\n");
    }
    
    // Ordena o array principal por título para as listagens.
    collSortTitle(&col);

    // Cria e ordena o índice de ponteiros (refs) por ISBN. 
    // É isto que nos permite ter duas ordenações ao mesmo tempo.
    collSortRefIsbn(&col);

    char command;
    char isbn_search[SIZE_ISBN];

    printf("> ");
    // Loop que espera por comandos do utilizador até que seja inserido 'q'.
    while (scanf(" %c", &command) == 1 && command != 'q') {
        switch (command) {
            case 'l':
            // Listagem simples de todos os livros.
                listBooks(&col);
                break;

            case 'i':
                // Lê o ISBN logo a seguir ao comando 'i'.
                if (scanf("%s", isbn_search) == 1) {
                    // Faz pesquisa binária rápida usando o array de referências.
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
                // Limpa caracteres "lixo" para o próximo comando não falhar.
                while (getchar() != '\n'); 
                break;
        }
        printf("> ");
    }
    return 0;
}