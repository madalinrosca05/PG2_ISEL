#include <stdio.h>
#include <string.h>
#include "errors.h"

/*
1.2. Escreva a função: 

int linePrintRaw( const char *line, void *context );
destinada a ser passada no parâmetro action da função anterior para apresentar, em standard output, o
conteúdo integral da linha de texto indicada em line.
A função retorna 1. O parâmetro context não é usado neste exercício; existe para compatibilidade de
assinatura, mas deve ser ignorado pelo código da função.
*/

    //printf retorna o numero de caracteres, entao, se der print a alguma coisa(printf > 0)
int linePrintRaw( const char *line, void *context ){  // retorna a logica da comparação, que é sempre 0 ou 1
    return (printf("%s", line) > 0); 
}