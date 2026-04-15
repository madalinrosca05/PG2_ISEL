#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "lineprint.h"
#include "processFile.h"

#define MAX_LINE_SIZE 512

/*
1.3. Escreva e teste um programa (com o nome prog21.c e executável prog21) para demostração das
funções anteriores. O programa recebe, em argumento de linha de comando, o nome de um ficheiro e
apresenta, em standard output, o seu conteúdo integral
*/
int main(int argc, char *argv[]){


    // Verificação das entradas
    if (argc != 1) {
        fatal_error("Erro nas entradas: ./prog21 <nome do ficheiro>\n");
    }
    char *ficheiro = argv[1];
    char line[MAX_LINE_SIZE];
    processFile(ficheiro,linePrintRaw(line,NULL), NULL);

    return 0;
}
