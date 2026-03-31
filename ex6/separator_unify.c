#include "separator_unify.h"

void separatorUnify(char str[]) {
    /*
        "i" é a posição atual de leitura na string original, 
        "j" é a posição de escrita na string modificada.
        "inSpace" indica se estamos atualmente em uma sequência de separadores 
        (espaços, tabs, novas linhas). 
        Começa a 1 porque ignora espaços iniciais.
    */ 
    int i = 0, j = 0, inSpace = 1; 

    while (str[i] != '\0') {

        // verifica se o carácter atual é um separador
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {

            // só escreve um espaço se não estiver já em sequência de espaços
            if (!inSpace) {
                str[j++] = ' ';
                inSpace = 1; // indica que agora estamos em espaço
            }

        } else {
            // se for um carácter "normal" (letra, número, etc.)
            str[j++] = str[i];   // copia para a nova posição
            inSpace = 0;         // indica que já não estamos em espaço
        }

        i++;
    }

    // se o último carácter escrito for espaço, remove-o
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0';
}