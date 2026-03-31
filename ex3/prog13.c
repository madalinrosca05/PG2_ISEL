#include <stdio.h>
#include "splitFields.h"

#define MAX_FIELDS 10
#define MAX_CHARS 256 // 255 carateres úteis + 1 para o '\0'

int main() {
    char *fields[MAX_FIELDS];
    char s[MAX_CHARS];

    // Lê linhas do stdin até EOF
    while (fgets(s, MAX_CHARS, stdin) != NULL) {
        
        // Aplica a função splitFields à linha lida
        int n = splitFields(s, fields, MAX_FIELDS);

        /* Apresenta os campos no formato {campo}.
           A função splitFields substitui os ';' por '\0', 
           por isso o printf para em cada separador.
        */
        for (int i = 0; i < n && i < MAX_FIELDS; ++i) {
            printf("{%s}", fields[i]);
        }
        
        /* Nota: Não adicionamos printf("\n") aqui porque o '\n' original 
           da linha lida pelo fgets já está preservado no último campo, 
           conforme exemplificado no enunciado.
        */
    }

    return 0;
}