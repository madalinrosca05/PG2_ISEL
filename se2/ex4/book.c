#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "book.h"
#include "splitFields.h"
#include "separator_unify.h"
#include "strcmp_ic.h"

// Função auxiliar para o qsort. Compara títulos de livros de forma case-insensitive.
// É static porque só interessa a este ficheiro. 
static int compareBooksByTitle(const void *a, const void *b) {
    const BookData *bookA = (const BookData *)a;
    const BookData *bookB = (const BookData *)b;
    return strcmp_ic(bookA->title, bookB->title);
}

// Lê uma linha do CSV, divide-a em campos e preenche a estrutura do livro.
int fillBookData(BookData *b, const char *line) {
    char line_copy[1024]; // Buffer suficiente para a linha completa
    char *fields[10];     // O ficheiro tem 10 campos
    
    // Uso uma cópia porque o splitFields altera a string original com '\0'
    strncpy(line_copy, line, sizeof(line_copy) - 1);
    line_copy[sizeof(line_copy) - 1] = '\0';

    // Divide a linha em campos utilizando a splitFields
    int n = splitFields(line_copy, fields, 10);
    if (n < 5) return 0; // Erro se não houver campos suficientes

    // Para cada campo, uniformizo os espaços e limito o tamanho para não ultrapassar os limites. 
    separatorUnify(fields[0]);
    strncpy(b->title, fields[0], MAX_TITLE - 1);
    b->title[MAX_TITLE - 1] = '\0';

    separatorUnify(fields[1]); 
    strncpy(b->isbn, fields[1], SIZE_ISBN - 1); 
    b->isbn[SIZE_ISBN - 1] = '\0';

    separatorUnify(fields[3]);
    strncpy(b->authors, fields[3], MAX_AUTHORS - 1);
    b->authors[MAX_AUTHORS - 1] = '\0';

    separatorUnify(fields[4]);
    strncpy(b->publisher, fields[4], MAX_PUB_NAME - 1);
    b->publisher[MAX_PUB_NAME - 1] = '\0';

    return 1;
}

// Função usada no processFile. Adiciona um livro à coleção.
int collAddBook(const char *line, void *context) {
    Collection *col = (Collection *)context;

    if (col->count >= MAX_BOOKS) return 0;

    if (fillBookData(&(col->books[col->count]), line)) {
        col->count++;
        return 1;
    }

    return 0;
}

// Ordena o array principal de livros por título.
void collSortTitle(Collection *col) {
    if (col->count > 0) {
        qsort(col->books, col->count, sizeof(BookData), compareBooksByTitle);
    }
}