%{
	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include <map>
	using namespace std;
	
	#include "y.tab.h"
	extern FILE *yyin;
	extern int yylex();
	extern int linenum;
	void yyerror(string s);
	
	string finalOutput="";
	string var="";
	map<string,int> values;
	map<string,int>::iterator itr;
%}

%union
{
int number;
char *str;
}

%token ASSIGNOP MINUSOP PLUSOP MULTOP DIVIDEOP
%token<str> INTEGER FLOAT
%token<str> VARIABLE STRING
%type<number> expression

%%
program:
    statement
	|
	statement program
    ;
statement:
	VARIABLE ASSIGNOP expression
	{
		values[string($1)] = $3;
		finalOutput+= "\t" + string($1) + " = " + var + ";\n";
		var="";
				
	}
    ;
	
expression:
	INTEGER	
	{
		$$=1;
		var+=string($1);
	}
	|
	FLOAT	
	{
		$$=2;
		var+=string($1);
	}
	|
	STRING	
	{
		$$=0;
		var+=string($1);
	}
	|
	VARIABLE
	{
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($1) || itr->first == string($1) || itr->first == string($1))
			{
				$$ = itr->second;
				var+=itr->first;
				break;
			}
		}
	}
	|
	expression operator expression  
	{
		if($1 == $3)	//control type mach
		{
			$$=$1;
		}
		else if($1 != $3 && $1 == 0 || $3 == 0)
		{
			cout<<"type mismatch in line "<<linenum<<endl;
			exit (EXIT_FAILURE);
		}
		else
		{
			$$=2;
		}
	}
    ;
	
	
operator:
	MINUSOP
	{
		var+=" - ";
	}
	|
	PLUSOP
	{
		var+=" + ";
	}
	|
	MULTOP
	{
		var+=" * ";
	}
	|
	DIVIDEOP
	{
		var+=" / ";
	}
	;

%%

void yyerror(string s){
	cout<<"error: "<<s<<endl;
}
int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
    
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
	
	cout<<"\nvoid main()\n{";
	int varNum=0;
	for (itr = values.begin(); itr != values.end(); ++itr)
	{
		if(itr->second == 1)
		{
			varNum++;
		}
	}
	if(varNum != 0)
	{
		cout<<"\n\tint ";
		for (itr = values.begin(); itr != values.end(); ++itr)
		{
			if(itr->second == 1 && varNum != 1)
			{
				cout<<itr->first<<", ";
				varNum--;
			}
			else if(itr->second == 1 && varNum == 1)
			{
				cout<<itr->first<<";"<< endl;
				varNum--;
			}
		}
	}
	
	varNum=0;
	for (itr = values.begin(); itr != values.end(); ++itr)
	{
		if(itr->second == 2)
		{
			varNum++;
		}
	}
	if(varNum != 0)
	{
		cout<<"\tfloat ";
		for (itr = values.begin(); itr != values.end(); ++itr)
		{
			if(itr->second == 2 && varNum != 1)
			{
				cout<<itr->first<<", ";
				varNum--;
			}
			else if(itr->second == 2 && varNum == 1)
			{
				cout<<itr->first<<";"<< endl;
				varNum--;
			}
		}
	}
	
	varNum=0;
	for (itr = values.begin(); itr != values.end(); ++itr)
	{
		if(itr->second == 0)
		{
			varNum++;
		}
	}
	if(varNum != 0)
	{
		cout<<"\tstring ";
		for (itr = values.begin(); itr != values.end(); ++itr)
		{
			if(itr->second == 0 && varNum != 1)
			{
				cout<<itr->first<<", ";
				varNum--;
			}
			else if(itr->second == 0 && varNum == 1)
			{
				cout<<itr->first<<";"<< endl;
				varNum--;
			}
		}
	}
	
	cout<< "\n"<<finalOutput<<endl;
	
	cout<<"}"<<endl;
    return 0;
}
