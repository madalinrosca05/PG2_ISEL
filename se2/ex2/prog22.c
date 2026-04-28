#include <stdio.h>
#include <string.h>
#include "processFile.h"
#include "lineFilterPrint.h"
#include "separator_unify.h"
#include "errors.h"

#define MAX_STR_SIZE 512

int main(int argc, char *argv[]) {
    // Aqui precisamos de dois argumentos: o ficheiro e a palavra a filtrar.
    if (argc != 3) {
        fatal_error("Uso: ./prog22 <nome do ficheiro> <string para filtrar>\n");
    }

    char *filename = argv[1];
    char search_str[MAX_STR_SIZE];

    // Copia a string de busca para a limpar.
    strncpy(search_str, argv[2], MAX_STR_SIZE - 1);
    search_str[MAX_STR_SIZE - 1] = '\0';
    
    // Unifica os separadores na string de busca para garantir que o "match" 
    // funciona mesmo que o utilizador ponha espaços a mais.
    separatorUnify(search_str);

    // O processFile vai chamar o lineFilterPrint para cada linha,
    // passando a search_str como contexto de comparação.
    int total_lines = processFile(filename, lineFilterPrint, search_str);

    if (total_lines < 0) {
        fatal_error("Erro: Não foi possível processar o ficheiro.\n");
    }

    printf("Total de linhas apresentadas: %d\n", total_lines);

    return 0;
}