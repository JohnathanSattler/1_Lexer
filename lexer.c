// Compiler Builder 8
// Lester Young
// Timothy Konzel
// Remington Howell
// Johnathan Sattler
// John Herold

// Included libraries
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "tokens.h"

// main function
int main(int argc, const char * argv[]) {

	sourceCode * code = NULL;

	handleInput(argc, argv, code);

    lexTest(code);
	return 0;
}

void lexTest(sourceCode *  code) {
    if (code == NULL)
        return;
    int lineNum, colNum = 0;
    while (code->c != NULL) {
        switch (code->c) {
        case '\n':
            lineNum++;
            colNum = 0;
            break;
        }
        colNum++;
        code = code->next;
    }

}
