lextest: lexer.o
	gcc -o lextest lexer.o

lexer.o: lexer.c tokens.h
	gcc -c lexer.c

clean:
	rm -f *.o