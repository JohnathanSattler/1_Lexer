typedef struct sourceCode {
	char c;
	struct sourceCode * next;
} sourceCode;

sourceCode * handleInput(int argc, const char * argv[], sourceCode * code);
sourceCode * readFile(const char * fileName, sourceCode * code);
void printCode(sourceCode * code, int source, int clean);
void printSourceCode(sourceCode * code, int source);
void printCleanCode(sourceCode * code, int clean);