typedef enum token {
  nulsym = 1, identsym, numbersym, plussym, minussym,
  multsym, slashsym, oddsym, eqsym, neqsym, lessym, leqsym,
  gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
  periodsym, becomessym, beginsym, endsym, ifsym, thensym,
  whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
  readsym , elsesym
} token_type;

char * reservedWords[] = {
	"const", "var", "procedure", "call", "begin",
	"end", "end", "if", "then", "else", "while",
	"do", "read", "write", "odd"
};

typedef struct tok {
	char * type;
	int id;
	struct tok * next;
} tok;
