#include <stdio.h>
#include <string.h>
#include "processFile.h"
#include "lineFilterPrint.h"
#include "separator_unify.h"
#include "errors.h"

#define MAX_STR_SIZE 512

int main(int argc, char *argv[]) {
    // Verificação de argumentos: nome do ficheiro e string de comparação 
    if (argc != 3) {
        fatal_error("Uso: ./prog22 <nome do ficheiro> <string para filtrar>\n");
    }

    char *filename = argv[1];
    char search_str[MAX_STR_SIZE];

    // Copiar a string de comparação para uma variável local e unificar os separadores
    strncpy(search_str, argv[2], MAX_STR_SIZE - 1);
    search_str[MAX_STR_SIZE - 1] = '\0';
    separatorUnify(search_str);

    // Processar o ficheiro e contar o número de linhas que correspondem à string de comparação
    int total_lines = processFile(filename, lineFilterPrint, search_str);

    if (total_lines < 0) {
        fatal_error("Erro: Não foi possível processar o ficheiro.\n");
    }

    printf("Total de linhas apresentadas: %d\n", total_lines);

    return 0;
}