%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int linenum=1;
int tabNum=0;
int ifNum=0;
int elseNum=0;
int elifNum=0;

%}
%%
:	return COLON;
!	return EXCLAMATION;
\<	return LESS;
\>	return GREATER;
=	return ASSIGNOP;
\-	return MINUSOP;
\+	return PLUSOP;
\/	return DIVIDEOP;
\*	return MULTOP;
elif	{elifNum++; if(ifNum == 0){printf("elif without if in line %d\n", linenum); exit (EXIT_FAILURE);}; return ELIF;}
if	{ifNum++; elseNum=0; return IFRSW;}
else	{elseNum++; if(ifNum == 0){printf("else without if in line %d\n", linenum); exit (EXIT_FAILURE);}; return ELSE;}
[-]?[0-9]+"."[0-9]+	{yylval.str = strdup(yytext); return FLOAT;}
[-]?[0-9]+	{yylval.str = strdup(yytext); return INTEGER;}
"\""[a-zA-Z0-9]+"\"" {yylval.str = strdup(yytext); return STRING;}
[a-z]([a-z]|[0-9])*	{yylval.str = strdup(yytext); return VARIABLE;}
[\t]+	{tabNum++; return TAB;}
\n	{linenum++;}
%%