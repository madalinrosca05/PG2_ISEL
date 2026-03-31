#include <stdio.h>
#include "strcmp_ic.h"

#define MAX_WORD 255

/* 
    O programa compara uma palavra fornecida como argumento da linha de comandos com 
    palavras lidas do stdin usando a função strcmp_ic para comparação case-insensitive. 
    Ele lê palavras do stdin até EOF (End Of File) ou erro de leitura, e para cada palavra lida 
    imprime o resultado da comparação com a palavra fornecida no argumento.
*/

int main (int argc, char *argv[]) {

/* 
    O "if" verifica se o utilizador forneceu uma palavra como argumento na linha de comandos. 
    Se não forneceu, argc = 1 (terá apenas o nome do programa em argv[0]) fazendo com que o programa
    imprima uma mensagem de erro e instruções de uso.
*/

    if (argc < 2) {
        printf ("Palavra proveniente do argumento da linha de comandos não inserida.\n");
        printf ("Uso: %s <palavra>\n", argv[0]);
        return 1;
    }

    char palavra_stdin[MAX_WORD + 1]; // "+1" para contar com o '\0'

    while (scanf("%255s", palavra_stdin) == 1) { // "%255s" para evitar overflow
        int res = strcmp_ic (argv[1], palavra_stdin);
        printf ("Comparação entre \"%s\" e \"%s\": %d\n", argv[1], palavra_stdin, res);
    }
    
    return 0;
}