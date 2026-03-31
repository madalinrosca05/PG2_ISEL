#include <stdio.h>
#include <stdlib.h>
#include "errors.h"


void fatal_error(const char *errorMsg){
    fprintf(stderr,"%s", errorMsg);
    exit(EXIT_FAILURE);
}