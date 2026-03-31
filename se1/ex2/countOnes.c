#include <stdio.h>
#include <limits.h>

/*
    countOnes: Conta o número de bits 1 em um valor unsigned.
    Se high não for NULL, armazena a posição do bit mais significativo 1 encontrado.
*/

static int INT_SIZE = sizeof(unsigned int) * CHAR_BIT;

int countOnes(unsigned value, int *high){
    int count = 0;
    for(int i = 0; i < INT_SIZE; i++){
        if((value & 1) == 1){
            count++;
            if (high != NULL) { 
                *high = i;
            }
        } 
        value >>= 1;
    }
    return count;
}