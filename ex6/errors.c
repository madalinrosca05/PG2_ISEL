#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

/*
    Implementação da função fatal_error, que recebe uma mensagem de erro como argumento, 
    imprime essa mensagem no fluxo de erro padrão (stderr) e encerra o programa com um 
    código de saída indicando falha (EXIT_FAILURE).
*/

void fatal_error(const char *errorMsg){
    fprintf(stderr,"%s", errorMsg);
    exit(EXIT_FAILURE);
}