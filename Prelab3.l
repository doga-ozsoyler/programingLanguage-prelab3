%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int linenum=1;

%}
%%
=	return ASSIGNOP;
\-	return MINUSOP;
\+	return PLUSOP;
\/	return DIVIDEOP;
\*	return MULTOP;
[-]?[0-9]+"."[0-9]+	{yylval.str = strdup(yytext); return FLOAT;}
[-]?[0-9]+	{yylval.str = strdup(yytext); return INTEGER;}
"\""[a-zA-Z0-9]+"\"" {yylval.str = strdup(yytext); return STRING;}
[a-z]([a-z]|[0-9])*	{yylval.str = strdup(yytext); return VARIABLE;}
\n	{linenum++;}
%%