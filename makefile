lextest: lexer.o input.o
	gcc -o lextest lexer.o input.o

lexer.o: lexer.c input.h tokens.h
	gcc -c lexer.c

input.o: input.c input.h
	gcc -c input.c

clean:
	rm -f *.o