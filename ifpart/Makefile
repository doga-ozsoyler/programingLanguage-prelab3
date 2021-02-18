all: lex yacc
	g++ lex.yy.c y.tab.c -ll -o ifpart

yacc: ifpart.y
	yacc -d ifpart.y

lex: ifpart.l
	lex ifpart.l
clean: 
	rm lex.yy.c y.tab.c  y.tab.h  ifpart
