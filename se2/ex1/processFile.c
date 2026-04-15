#include <stdio.h>
#include <string.h>
#include "errors.h"

/*
Escreva a função:

int processFile( const char *filename,
int (*action)( const char *line, void *context ),
void *context );
que abre o ficheiro com o nome indicado, lê o seu conteúdo linha a linha e aplica a cada linha o
processamento implementado pela função passada em action. Ao executar esta função action, deve
passar uma string com a linha a processar e o parâmetro context recebido.
A função retorna a soma dos valores retornados por todas as chamadas à função action.
Sugere-se que realize a leitura do ficheiro de entrada com a função fgets. Propõe-se a dimensão de 512
carateres para a memória destinada ao armazenamento da linha.
*/
//sugerido usar fgets, 512 caracteres para a memoria destinada ao armazenamento da linha
#define MAX_LINE_SIZE 512

int processFile( const char *filename, int (*action)( const char *line, void *context ), void *context ){
    int action_sum = 0;
    char linha_lida[MAX_LINE_SIZE];
    
    if (filename == NULL){fatal_error("ficheiro inválido");}

    // arranjar isto: está a ler o nome do ficheiro em vez do ficheiro "/
    while ( fgets(linha_lida, MAX_LINE_SIZE, *filename)!= NULL) 
    {
        action_sum += action(linha_lida, context); 
    }
return action_sum;
}