#include <stdio.h>
#include <string.h>
#include "lineFilterPrint.h"
#include "splitFields.h"
#include "separator_unify.h"
#include "strcmp_ic.h"

#define MAX_LINE_SIZE 512

int lineFilterPrint(const char *line, void *context) {
    char line_copy[MAX_LINE_SIZE];
    char *fields[1]; // Só precisamos do primeiro campo
    const char *target = (const char *)context;

    // Criar uma cópia porque splitFields e separatorUnify modificam a string
    strncpy(line_copy, line, MAX_LINE_SIZE - 1);
    line_copy[MAX_LINE_SIZE - 1] = '\0';

    // Separar os campos (o primeiro campo começa no início de line_copy)
    int n_fields = splitFields(line_copy, fields, 1);

    if (n_fields > 0) {
        // Uniformizar o primeiro campo extraído
        separatorUnify(fields[0]);

        // Comparar com o critério (context) de forma case-insensitive
        if (strcmp_ic(fields[0], target) == 0) {
            // Se coincidir, imprimir a linha ORIGINAL e retornar 1
            printf("%s", line);
            return 1;
        }
    }

    return 0; // Caso contrário, retornar 0
}