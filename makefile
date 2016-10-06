# Compiler Builder 8
# Lester Young
# Timothy Konzel
# Remington Howell
# Johnathan Sattler
# John Herold

lexer: lexer.o parse.o input.o printing.o
	gcc -o lexer lexer.o parse.o input.o printing.o

lexer.o: lexer.c lexer.h parse.h input.h printing.h tokens.h
	gcc -c lexer.c

parse.o: parse.c parse.h tokens.h
	gcc -c parse.c

input.o: input.c input.h tokens.h
	gcc -c input.c

printing.o: printing.c printing.h tokens.h
	gcc -c printing.c

clean:
	rm -f *.o lexer