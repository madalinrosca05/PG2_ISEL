#include <stdio.h>
#include "calcParity.h"

int main(){
    unsigned int num;
    int paridade;
    
    while (printf("insira a sequência: "), scanf("%u", &num) == 1) // Uso de %u para unsigned
    {
        paridade = calcParity(num);
        if (paridade == 1) {
            printf("%u é Impar!\n", num);
        } else {
            printf("%u é Par!\n", num);
        }
    }
    return 0;
}