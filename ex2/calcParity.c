#include "calcParity.h"
#include "countOnes.h"

int calcParity(unsigned value){
    int high = 0;
    unsigned int count = countOnes(value, &high);
    if (count % 2 == 0){
        return 0;
    }
    return 1;
}
