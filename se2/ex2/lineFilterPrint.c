#include <stdio.h>
#include <string.h>
#include "lineFilterPrint.h"
#include "splitFields.h"
#include "separator_unify.h"
#include "strcmp_ic.h"

#define MAX_LINE_SIZE 512

// Verifica se o primeiro campo da linha coincide com o 'target' passado no contexto.
int lineFilterPrint(const char *line, void *context) {
    char line_copy[MAX_LINE_SIZE];
    char *fields[1]; // // Só preciso do primeiro campo para comparar
    const char *target = (const char *)context;

    /* Crio uma cópia da linha porque as funções splitFields e separatorUnify 
       são destrutivas (alteram a string). Se mudasse a 'line' original, 
       depois não conseguia imprimir a linha correta no printf final.
    */
    strncpy(line_copy, line, MAX_LINE_SIZE - 1);
    line_copy[MAX_LINE_SIZE - 1] = '\0';

    // Extraio apenas o início da linha (até ao primeiro ';')
    int n_fields = splitFields(line_copy, fields, 1);

    if (n_fields > 0) {
        // Limpo espaços extra do campo extraído para a comparação ser justa
        separatorUnify(fields[0]);

        // Comparação case-insensitive para o filtro ser mais flexível
        if (strcmp_ic(fields[0], target) == 0) {
            // Se houver match, imprimo a linha ORIGINAL (com todos os campos e sem cortes)
            printf("%s", line);
            return 1;
        }
    }

    return 0; // Caso contrário, retornar 0
}