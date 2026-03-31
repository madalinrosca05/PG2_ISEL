#include <stdio.h>
#include "splitFields.h"

#define MAX_FIELDS 10
#define MAX_CHARS 256 

int main() {
    char *fields[MAX_FIELDS];
    char s[MAX_CHARS];

    // Lê linhas do stdin até EOF
    while (fgets(s, MAX_CHARS, stdin) != NULL) {
        
        int n = splitFields(s, fields, MAX_FIELDS);

        /* Apresenta os campos no formato {campo}.
           A função splitFields substitui os ';' por '\0', 
           por isso o printf para em cada separador.
        */
        for (int i = 0; i < n && i < MAX_FIELDS; ++i) {
            printf("{%s}", fields[i]);
        }
        /*
            Não é necessário imprimir um '\n' no final, porque o fgets já inclui o '\n' na string 
            lida, e o printf irá imprimir esse '\n' após o último campo, mantendo a formatação correta.
        */
    }

    return 0;
}