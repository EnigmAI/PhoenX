lexer: main.c lexer.c
	cc -o lexer -g main.c lexer.c

clean:
	rm -f lexer *.o
