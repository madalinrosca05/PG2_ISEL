#include <stdio.h>
#include <string.h>
#include "errors.h"

#define MAX_LINE_SIZE 512

// Abre o ficheiro e aplica a função 'action' a cada linha lida.
// O 'context' permite passar dados (como a nossa Collection) para dentro da função action.
int processFile(const char *filename, int (*action)(const char *line, void *context), void *context) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }

    int action_sum = 0;
    char linha_lida[MAX_LINE_SIZE];

    while (fgets(linha_lida, MAX_LINE_SIZE, f) != NULL) {
        // Soma os retornos da action para sabermos, por exemplo, quantos livros foram lidos
        action_sum += action(linha_lida, context);
    }

    fclose(f);
    return action_sum;
}