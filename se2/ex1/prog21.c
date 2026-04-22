#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "lineprint.h"
#include "processFile.h"

#define MAX_LINE_SIZE 512

/*
Escreva e teste um programa (com o nome prog21.c e executável prog21) para demostração das
funções anteriores. O programa recebe, em argumento de linha de comando, o nome de um ficheiro e
apresenta, em standard output, o seu conteúdo integral
*/

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fatal_error("Uso: ./prog21 <nome do ficheiro>\n");
    }
    
    char *ficheiro = argv[1];
    processFile(ficheiro, linePrintRaw, NULL);

    return 0;
}
