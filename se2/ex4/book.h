#ifndef BOOK_H
#define BOOK_H

#include "strcmp_ic.h"
// Defini as dimensões com uma margem de segurança baseada no ficheiro dados.csv
#define MAX_BOOKS     350   // Superior às 296 linhas (livros) contadas
#define MAX_TITLE     256   // Superior aos 200 carateres do título mais longo
#define SIZE_ISBN     20    // Superior aos 10 carateres
#define MAX_AUTHORS   128   // Superior aos 92 carateres do campo de autores
#define MAX_PUB_NAME  64    // Superior aos 51 carateres do campo da editora

typedef struct book {
    char title[MAX_TITLE];
    char isbn[SIZE_ISBN];
    char authors[MAX_AUTHORS];
    char publisher[MAX_PUB_NAME];
} BookData;

typedef struct {
    BookData books[MAX_BOOKS]; // Array com os dados reais
    BookData *refs[MAX_BOOKS]; // Array de ponteiros para ordenação/pesquisa por ISBN
    int count; 
} Collection;

<<<<<<< HEAD
// Protótipos das funções públicas
=======
void collSortTitle (Collection *col);
>>>>>>> e242d5db1006860ff56d224d7693354097149816
int fillBookData(BookData *b, const char *line);
int collAddBook(const char *line, void *context);
#endif