
#include "separator_unify.h"

/*
 * Função: separatorUnify
 * ----------------------
 * Recebe uma string e uniformiza os separadores entre palavras:
 * - Substitui qualquer sequência de espaços, tabs ou newlines por um único espaço
 * - Remove separadores no início e no fim da string
 * - O processamento é feito na própria string (sem memória extra)
 */
void separatorUnify(char str[]) {
    
    int i = 0, j = 0;
    // i -> índice de leitura
    // j -> índice de escrita

    int inSpace = 1;
    // indica se estamos "dentro de separadores"
    // começa a 1 para ignorar espaços iniciais

    
    while (str[i] != '\0') {

        // verifica se o carácter atual é um separador
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {

            // só escreve um espaço se não estiver já em sequência de espaços
            if (!inSpace) {
                str[j++] = ' ';   // escreve um único espaço
                inSpace = 1;      // marca que agora está em espaço
            }

        } else {
            // se for um carácter "normal" (letra, número, etc.)
            str[j++] = str[i];   // copia para a nova posição
            inSpace = 0;         // indica que já não estamos em espaço
        }

        i++; // avança para o próximo carácter
    }

    // se o último carácter escrito for espaço, remove-o
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    // termina a string corretamente
    str[j] = '\0';
}