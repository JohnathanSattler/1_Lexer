// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokens.h"

sourceCode * handleInput(int argc, const char * argv[], sourceCode * code, int * s, int * c);
sourceCode * readFile(const char * fileName, sourceCode * code);
