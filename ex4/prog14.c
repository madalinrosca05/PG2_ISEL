#include <stdio.h>
#include "splitFields.h"
#include "separator_unify.h"

#define MAX_LINE 256
#define MAX_FIELDS 50

/*
    O programa lê linhas de texto da entrada padrão, divide cada linha em campos usando a função 
    splitFields, unifica os separadores de cada campo usando a função separatorUnify, 
    e imprime cada campo.
*/

int main() {
    char line[MAX_LINE];
    char *fields[MAX_FIELDS];

    while (fgets(line, MAX_LINE, stdin) != NULL) {

        int n = splitFields(line, fields, MAX_FIELDS);

        for (int i = 0; i < n && i < MAX_FIELDS; i++) {
            separatorUnify(fields[i]);   
            printf("{%s}", fields[i]);
        }

        printf("\n");
    }

    return 0;
}