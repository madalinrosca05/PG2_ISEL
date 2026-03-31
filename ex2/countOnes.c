#include <stdio.h>
#include <limits.h>

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