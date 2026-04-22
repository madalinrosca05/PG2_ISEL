#ifndef BOOK_H
#define BOOK_H

// 3.1. Dimensões baseadas na análise real de dados.csv
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
    BookData books[MAX_BOOKS];
    BookData *refs[MAX_BOOKS]; 
    int count; 
} Collection;

int fillBookData(BookData *b, const char *line);
int collAddBook(const char *line, void *context);

#endif