#include <stdio.h>
#include <string.h>
#include "book.h"
#include "splitFields.h"
#include "separator_unify.h"

// 3.2. Preencher a estrutura com os dados da linha
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

// 3.3. Adicionar um livro à coleção usando a função collAddBook
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