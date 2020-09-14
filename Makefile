compiler: cg.c parser.c asm.c interpreter.c main.c lexer.c tree.c
	cc -o compiler -g cg.c parser.c asm.c interpreter.c main.c lexer.c tree.c

clean:
	rm -f compiler *.o *.s out
	
run: compiler
	./compiler test
	cc -o out out.s
