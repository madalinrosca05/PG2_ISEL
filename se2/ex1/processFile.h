#include <stdio.h>
#include <string.h>
#include "errors.h"


int processFile( const char *filename, int (*action)( const char *line, void *context ), void *context );