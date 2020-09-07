parser: parser.c interpreter.c main.c lexer.c tree.c
	cc -o parser -g parser.c interpreter.c main.c lexer.c tree.c

clean:
	rm -f parser *.o
