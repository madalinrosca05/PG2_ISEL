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

        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {

            // só escreve um espaço se não estiver já em sequência de espaços
            if (!inSpace) {
                str[j++] = ' ';
                inSpace = 1; // indica que agora estamos em espaço
            }

        } else {
            // se for um carácter "normal" (letra, número, etc.) copia para a nova pos/ indica que não temos espaço
            str[j++] = str[i]; 
            inSpace = 0;       
        }

        i++;
    }

    // se o último carácter escrito for espaço, remove-o
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0';
}