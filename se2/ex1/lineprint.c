#include <stdio.h>
#include <string.h>
#include "errors.h"

    //printf retorna o numero de caracteres, entao, se der print a alguma coisa(printf > 0)
int linePrintRaw( const char *line, void *context ){  // retorna a logica da comparação, que é sempre 0 ou 1
    return (printf("%s", line) > 0); 
}