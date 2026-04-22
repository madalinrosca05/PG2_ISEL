#include <stdio.h>
#include <string.h>
#include "errors.h"

#define MAX_LINE_SIZE 512

int processFile(const char *filename, int (*action)(const char *line, void *context), void *context) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1; // Ou tratar com fatal_error
    }

    int action_sum = 0;
    char linha_lida[MAX_LINE_SIZE];

    while (fgets(linha_lida, MAX_LINE_SIZE, f) != NULL) {
        action_sum += action(linha_lida, context);
    }

    fclose(f);
    return action_sum;
}