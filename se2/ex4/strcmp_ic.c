#include <stdio.h>
#include <ctype.h>
#include "strcmp_ic.h"

/*  
    Implementação da função strcmp_ic, que compara duas strings de forma case-insensitive.
    A função percorre ambas as strings simultaneamente, convertendo os caracteres para minúsculas
    usando tolower() antes de compará-los. 
    O loop continua enquanto os caracteres correspondentes forem iguais e não for atingido o final 
    de nenhuma string.
    Quando o loop termina, a função retorna a diferença entre os caracteres onde as strings diferem, 
    ou 0 se forem iguais.  
*/ 

int strcmp_ic(const char *str1, const char *str2) {


    while (*str1 != '\0' && tolower((unsigned char) *str1) == tolower((unsigned char) *str2)) { 
        str1++;
        str2++;
    }

    return tolower((unsigned char) *str1) - tolower((unsigned char) *str2); 
}