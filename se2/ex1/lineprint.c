#include <stdio.h>
#include <string.h>
#include "errors.h"

// Função simples que imprime a linha tal como ela vem do ficheiro.
int linePrintRaw( const char *line, void *context ){
    /* O printf retorna o número de caracteres impressos. 
       Se for maior que 0, significa que a linha foi impressa com sucesso, 
       então retorno 1 (true) para o contador do processFile.
    */
    return (printf("%s", line) > 0); 
}