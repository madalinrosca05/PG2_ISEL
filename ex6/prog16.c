#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "splitFields.h"
#include "separator_unify.h"
#include "strcmp_ic.h"

#define MAX_LINE_SIZE 256 // 255 carateres úteis + '\0'
#define MAX_FIELDS 50

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fatal_error("Uso: ./prog16 <posicao_campo> <string_comparar>\n");
    }

    int pos_campo = (int)strtoul(argv[1], NULL, 10);
    if (pos_campo <= 0) {
        fatal_error("Erro: A posição do campo deve ser >= 1.\n");
    }
 
    char str_procurada[MAX_LINE_SIZE];
    strncpy(str_procurada, argv[2], MAX_LINE_SIZE - 1);
    str_procurada[MAX_LINE_SIZE - 1] = '\0';
    separatorUnify(str_procurada); 

    char linha[MAX_LINE_SIZE];
    char linha_copia[MAX_LINE_SIZE];
    char *fields[MAX_FIELDS];

    while (fgets(linha, MAX_LINE_SIZE, stdin) != NULL) { 
        strcpy(linha_copia, linha);
        int n_campos = splitFields(linha_copia, fields, MAX_FIELDS);

        if (pos_campo <= n_campos) {
            char *campo_alvo = fields[pos_campo - 1]; 
            separatorUnify(campo_alvo);

            if (strcmp_ic(campo_alvo, str_procurada) == 0) {
                printf("%s", linha);
            }
        }
    }

    return 0;
}