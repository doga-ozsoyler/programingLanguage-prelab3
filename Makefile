all: lex yacc
	g++ lex.yy.c y.tab.c -ll -o Prelab3

yacc: Prelab3.y
	yacc -d Prelab3.y

lex: Prelab3.l
	lex Prelab3.l
clean: 
	rm lex.yy.c y.tab.c  y.tab.h  Prelab3
