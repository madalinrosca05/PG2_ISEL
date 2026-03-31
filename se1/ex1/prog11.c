#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "countOnes.h"

int main(){
    int value_to_count;
    int high = 0;
    while (true){
    printf("insira o valor:\n");
    if(scanf("%d", &value_to_count) != 1){
        printf("valor inválido, reinicie o programa \n\n");
        break;
    }
    int count = countOnes(value_to_count, &high);
    printf("count:%d\n high: %d\n", count, high);
 }
 return 0;

}
