#include "calcParity.h"
#include "countOnes.h"

/*
    Calcula a paridade de um valor unsigned.
    Retorna 0 se o número de bits 1 for par, 1 caso contrário.
*/

int calcParity(unsigned value){
    int high = 0;
    unsigned int count = countOnes(value, &high);
    if (count % 2 == 0){
        return 0;
    }
    return 1;
}
