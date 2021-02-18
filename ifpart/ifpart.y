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
	extern int tabNum;
	extern int ifNum;
	extern int elseNum;
	extern int elifNum;
	void yyerror(string s);
	
	string finalOutput="";
	string var="";
	string ifVar="";
	string ifVarInside="";
	string elseVar="";
	string elifVar="";
	string ifInElse="";
	string elseInIf="";
	string ifInIf="";
	int tabIf=0;
	map<string,int> values;
	map<string,int>::iterator itr;
%}

%union
{
int number;
char *str;
}

%token ASSIGNOP IFRSW COLON EXCLAMATION LESS GREATER ELSE ELIF MINUSOP PLUSOP MULTOP DIVIDEOP
%token<str> INTEGER FLOAT TAB
%token<str> VARIABLE STRING
%type<number> var_type if_expression

%%
program:
    statement
	|
	statement program
    ;
statement:
	IFRSW if_case COLON if_body
	{
		cout<<"A"<<endl;
		finalOutput+= ifVar + ifInIf + elseInIf + "\t}\n";
		ifVar="";
		elseInIf="";
	}
	|
	IFRSW if_case COLON
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block"<<endl;
		exit (EXIT_FAILURE);
	}
	|
	ELIF elif_case COLON elif_body
	{
		cout<<"B"<<endl;
		finalOutput+= elifVar + "\t}\n";
		elifVar="";
	}
	|
	ELIF elif_case COLON
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block"<<endl;
		exit (EXIT_FAILURE);
	}
	|
	ELSE COLON else_body
	{
		cout<<"C"<<endl;
		finalOutput+= "\telse\n\t{\n" + elseVar + "\t}\n";
		elseVar="";
	}
	|
	ELSE COLON
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block"<<endl;
		exit (EXIT_FAILURE);
	}
    ;
	
if_body:
	if_statement
	|
	if_statement if_body
	;
	
elif_body:
	elif_statement
	|
	elif_statement elif_body
	;

else_body:
	else_statement
	|
	else_statement else_body
	;

if_statement:
	TAB VARIABLE ASSIGNOP if_expression
	{
		cout<<"D "<<$2<<endl;
		ifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($2)+"_int" || itr->first == string($2)+"_flt" || itr->first == string($2)+"_str")
			{
				ifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if($4 == 1)
			{
				values[string($2)+"_int"] = $4;
				ifVar+= "\t" + string($2) + "_int";
			}
			else if($4 == 2)
			{
				values[string($2)+"_flt"] = $4;
				ifVar+= "\t" + string($2) + "_flt";
			}
			else if($4 == 0)
			{
				values[string($2)+"_str"] = $4;
				ifVar+= "\t" + string($2) + "_str";
			}
		}
		ifVar+= " = " + var + ";\n";
		var="";
	}
	|
	TAB IFRSW if_case COLON if_body
	{
		cout<<"E"<<endl;
		ifInIf+= ifVar + elseInIf + "\t}\n";
		ifVar="";
		elseInIf="";
	}
	|
	TAB ELSE COLON else_body
	{
		cout<<"F"<<endl;
		cout<<ifInElse<<endl;
		elseInIf+= "\telse\n\t{\n" + elseVar + ifInElse + "\t}\n";
		elseVar="";
		ifInElse="";
	}
	;
	
elif_statement:
	TAB VARIABLE ASSIGNOP if_expression
	{
		cout<<"G "<<$2<<endl;
		elifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($2)+"_int" || itr->first == string($2)+"_flt" || itr->first == string($2)+"_str")
			{
				elifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if($4 == 1)
			{
				values[string($2)+"_int"] = $4;
				elifVar+= "\t" + string($2) + "_int";
			}
			else if($4 == 2)
			{
				values[string($2)+"_flt"] = $4;
				elifVar+= "\t" + string($2) + "_flt";
			}
			else if($4 == 0)
			{
				values[string($2)+"_str"] = $4;
				elifVar+= "\t" + string($2) + "_str";
			}
		}
		elifVar+= " = " + var + ";\n";
		var="";
	}
	;

else_statement:
	TAB VARIABLE ASSIGNOP if_expression
	{	
		cout<<"H "<<$2<<endl;
		elseVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($2)+"_int" || itr->first == string($2)+"_flt" || itr->first == string($2)+"_str")
			{
				elseVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if($4 == 1)
			{
				values[string($2)+"_int"] = $4;
				elseVar+= "\t" + string($2) + "_int";
			}
			else if($4 == 2)
			{
				values[string($2)+"_flt"] = $4;
				elseVar+= "\t" + string($2) + "_flt";
			}
			else if($4 == 0)
			{
				values[string($2)+"_str"] = $4;
				elseVar+= "\t" + string($2) + "_str";
			}
		}
		elseVar+= " = " + var + ";\n";
		var="";
	}
	|
	TAB IFRSW if_case COLON if_body
	{
		cout<<"I"<<endl;
		cout<<ifVar<<endl;
		ifInElse+= ifVar + "\t}\n";
		ifVar="";
	}
	;

if_case:
	var_type case_type var_type
	{
		if($1 == $3)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 == 9 || $3 == 9)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 != $3 && $1 != 0 && $3 != 0)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else
		{
			cout<< "comparison type mismatch in line " << linenum << endl;
			exit (EXIT_FAILURE);
		}
	}
	;

elif_case:
	var_type case_type var_type
	{
		if(elseNum != 0)
		{
			cout<<"elif after else in line " << linenum << endl;
			exit (EXIT_FAILURE);
		}
		
		if($1 == $3)
		{
			elifVar+= "\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 == 9 || $3 == 9)
		{
			elifVar+= "\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if($1 != $3 && $1 != 0 && $3 != 0)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else
		{
			cout<< "comparison type mismatch in line " << linenum << endl;
			exit (EXIT_FAILURE);
		}
		
	}
	;

var_type:
	VARIABLE
	{
		bool check = 0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($1)+"_int" || itr->first == string($1)+"_flt" || itr->first == string($1)+"_str")
			{
				ifVarInside+=itr->first;
				$$=itr->second;
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			ifVarInside+=string($1);
			$$=9;
			
		}
	}
	|
	INTEGER
	{
		ifVarInside+=string($1);
		$$=1;
	}
	|
	FLOAT
	{
		ifVarInside+=string($1);
		$$=2;
	}
	|
	STRING
	{
		ifVarInside+=string($1);
		$$=0;
	}
	;
	
case_type:
	ASSIGNOP ASSIGNOP
	{
		ifVarInside+= " == ";
	}
	|
	EXCLAMATION ASSIGNOP
	{
		ifVarInside+= " != ";
	}
	|
	LESS
	{
		ifVarInside+= " < ";
	}
	|
	LESS ASSIGNOP
	{
		ifVarInside+= " <= ";
	}
	|
	GREATER
	{
		ifVarInside+= " > ";
	}
	|
	GREATER ASSIGNOP
	{
		ifVarInside+= " >= ";
	}
	;
	
if_expression:
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
		bool check = 0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string($1)+"_int" || itr->first == string($1)+"_flt" || itr->first == string($1)+"_str")
			{
				$$ = itr->second;
				var+=itr->first;
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			var+=string($1);	
		}
	}
	|
	if_expression operator if_expression  
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
	
	cout<< "\n"<<finalOutput<<endl;
	
	cout<<"}"<<endl;
    return 0;
}
