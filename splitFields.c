#include <stdio.h>
#include "splitFields.h"

/*
    Separa os campos de uma string usando ';' como delimitador.
    Substitui cada ';' por '\0' e armazena o início de cada campo em fields[].
*/

int splitFields(char *str, char *fields[], int max) {
    if (str == NULL || *str == '\0') {
        return 0; 
    }

    int field_count = 0;

    // O primeiro campo começa sempre no início da string str
    if (field_count < max) {
        fields[field_count] = str;
    }
    field_count++;

    // Percorrer a string caracter a caracter
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';') {
            // Substituir ';' por '\0' para terminar o campo atual
            str[i] = '\0';

            // Determinar o início do próximo campo
            char *next_field_start = &str[i + 1];

            // Registrar o início do próximo campo se ainda houver espaço no array fields
            if (field_count < max) {
                fields[field_count] = next_field_start;
            }

            // Incrementar o contador de campos
            field_count++;
        }
    }

    return field_count;
}

