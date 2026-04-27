#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "book.h"
#include "splitFields.h"
#include "separator_unify.h"
#include "strcmp_ic.h"

// Função auxiliar de comparação para qsort, comparando os títulos dos livros de forma case-insensitive
static int compareBooksByTitle(const void *a, const void *b) {
    const BookData *bookA = (const BookData *)a;
    const BookData *bookB = (const BookData *)b;
    return strcmp_ic(bookA->title, bookB->title);
}

// 4.1. Função para ordenar a coleção de livros por título
void collSortTitle(Collection *col) {
    if (col->count > 0) {
        qsort(col->books, col->count, sizeof(BookData), compareBooksByTitle);
    }
}

int fillBookData(BookData *b, const char *line) {
    char line_copy[1024]; // Buffer suficiente para a linha completa
    char *fields[10];     // O ficheiro tem 10 campos
    
    strncpy(line_copy, line, sizeof(line_copy) - 1);
    line_copy[sizeof(line_copy) - 1] = '\0';

    // Dividir a linha em campos utilizando a splitFields
    int n = splitFields(line_copy, fields, 10);
    if (n < 5) return 0; // Erro se não houver campos suficientes

    // Copiar e uniformizar os campos relevantes (Título, ISBN, Autores, Editora)
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


int collAddBook(const char *line, void *context) {
    Collection *col = (Collection *)context;

    // Verificar se há espaço na coleção
    if (col->count >= MAX_BOOKS) return 0;

    // Preencher os dados do livro e adicionar à coleção
    if (fillBookData(&(col->books[col->count]), line)) {
        col->count++;
        return 1;
    }

    return 0;
}

//---------- adicionado no ex5

void listBooks(Collection *col) { //--- falta adicionar para mostrar quando uso o comando 'i'
    collSortTitle(col); 
    for (int i = 0; i < col->count; i++) {
        BookData *b = &col->books[i];
        printf("%s; %s; %s; %s\n", 
               b->title, b->authors, b->publisher, b->isbn);
    }
}

// Função auxiliar de comparação para ordenar ponteiros de livros por ISBN
static int compareByIsbn(const void *a, const void *b) {
    // Como qsort passa ponteiros para os elementos do array, 
    // e o array contém (BookData *), 'a' e 'b' são (BookData **)
    const BookData *bookA = *(const BookData **)a;
    const BookData *bookB = *(const BookData **)b;
    
    return strcmp(bookA->isbn, bookB->isbn);
}

void collSortRefIsbn(Collection *col) {
    if (col->count <= 0) return;

    // 1. Inicializar o array de referências
    // Cada posição i de 'refs' aponta para a posição i de 'books'
    for (int i = 0; i < col->count; i++) {
        col->refs[i] = &(col->books[i]);
    }

    // 2. Ordenar o array de ponteiros 'refs' por ISBN
    // Note que o tamanho de cada elemento é sizeof(BookData *)
    qsort(col->refs, col->count, sizeof(BookData *), compareByIsbn);
}

// Função de comparação para o bsearch
// O primeiro argumento é a chave (string ISBN), o segundo é um elemento do array refs (BookData**)
static int compareKeyWithIsbn(const void *key, const void *element) {
    const char *isbnKey = (const char *)key;
    const BookData *book = *(const BookData **)element;
    return strcmp(isbnKey, book->isbn);
}

BookData* collSearchIsbn(Collection *col, const char *isbn) {
    if (col->count <= 0) return NULL;

    // bsearch retorna um ponteiro para o elemento encontrado no array refs.
    // Como refs é um array de BookData*, o retorno é um BookData**
    BookData **res = bsearch(isbn, col->refs, col->count, sizeof(BookData *), compareKeyWithIsbn);

    if (res == NULL) return NULL;
    return *res; // Retorna o ponteiro para o livro
}