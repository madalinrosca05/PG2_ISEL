#include <stdio.h>
#include "splitFields.h"

// Parte a string str nos delimitadores ';', substituindo-os por '\0'.
// Guarda os ponteiros para o início de cada campo no array fields.
int splitFields(char *str, char *fields[], int max) {
    if (str == NULL || *str == '\0') { 
        return 0; 
    }

    int field_count = 0;

    // O primeiro campo começa obrigatoriamente no início da string
    if (field_count < max) {
        fields[field_count] = str;
    }
    field_count++;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';') {
            str[i] = '\0'; // "Corta" a string original aqui.
            char *next_field_start = &str[i + 1]; // Determinar o início do próximo campo

            if (field_count < max) {
                fields[field_count] = next_field_start;
            }
            
            field_count++;
        }
    }

    return field_count;
}

