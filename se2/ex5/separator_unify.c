#include "separator_unify.h"

// Remove espaços/tabs repetidos e espaços nas extremidades, deixando apenas um espaço entre palavras.
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

<<<<<<< HEAD
        // Verifica se o carácter atual é um separador
=======
>>>>>>> e242d5db1006860ff56d224d7693354097149816
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {

            // Só escreve um espaço se não estiver já em sequência de espaços
            if (!inSpace) {
                str[j++] = ' ';
                inSpace = 1; // Indica que agora estamos em espaço
            }

        } else {
<<<<<<< HEAD
            // Se for um carácter "normal" (letra, número, etc.)
            str[j++] = str[i];   // Copia para a nova posição
            inSpace = 0;         // Indica que já não estamos em espaço
=======
            // se for um carácter "normal" (letra, número, etc.) copia para a nova pos/ indica que não temos espaço
            str[j++] = str[i]; 
            inSpace = 0;       
>>>>>>> e242d5db1006860ff56d224d7693354097149816
        }

        i++;
    }

    // Se a string terminou com um espaço extra, recuamos o cursor para o eliminar
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }

    str[j] = '\0';
}