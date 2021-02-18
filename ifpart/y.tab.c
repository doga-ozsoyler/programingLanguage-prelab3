/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "ifpart.y"

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
#line 32 "ifpart.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
int number;
char *str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 64 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ASSIGNOP 257
#define IFRSW 258
#define COLON 259
#define EXCLAMATION 260
#define LESS 261
#define GREATER 262
#define ELSE 263
#define ELIF 264
#define MINUSOP 265
#define PLUSOP 266
#define MULTOP 267
#define DIVIDEOP 268
#define INTEGER 269
#define FLOAT 270
#define TAB 271
#define VARIABLE 272
#define STRING 273
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    3,    3,    3,    3,    3,    5,    5,
    7,    7,    8,    8,    9,    9,    9,   10,   11,   11,
    4,    6,    1,    1,    1,    1,   12,   12,   12,   12,
   12,   12,    2,    2,    2,    2,    2,   13,   13,   13,
   13,
};
static const YYINT yylen[] = {                            2,
    1,    2,    4,    3,    4,    3,    3,    2,    1,    2,
    1,    2,    1,    2,    4,    5,    4,    4,    4,    5,
    3,    3,    1,    1,    1,    1,    2,    2,    1,    2,
    1,    2,    1,    1,    1,    1,    3,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,   24,   25,   23,   26,    0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,    7,    0,    0,    0,   27,   28,   30,   32,
   21,    0,    3,    0,    0,    0,   14,   22,    0,    5,
    0,    0,    0,    0,   10,    0,    0,    0,   12,    0,
    0,    0,    0,   33,   34,   36,   35,    0,    0,    0,
   17,    0,   20,   38,   39,   40,   41,    0,    0,   16,
    0,
};
static const YYINT yydgoto[] = {                          4,
   10,   58,    5,   11,   33,   14,   40,   23,   34,   41,
   24,   20,   68,
};
static const YYINT yysindex[] = {                      -226,
 -224, -253, -224,    0, -226,    0,    0,    0,    0, -218,
 -252, -261, -218, -247,    0, -241, -233, -223, -217, -224,
 -240, -250,    0, -261, -224, -230,    0,    0,    0,    0,
    0, -249,    0, -240, -224, -210,    0,    0, -220,    0,
 -230, -224, -202, -195,    0, -190, -219, -187,    0, -188,
 -261, -219, -240,    0,    0,    0,    0, -200, -219, -240,
    0, -200,    0,    0,    0,    0,    0, -219, -200,    0,
 -200,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,   72,    0,    0,    0,    0,    0,
    0,   17,    0,    0,    0,    0,    0, -214, -209,    0,
   19,    0,    0,   26,    0,   29,    0,    0,    0,    0,
    0,    0,    0,   33,    0,    0,    0,    0,    0,    0,
   36,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    5,    0,
   15,
};
static const YYINT yygindex[] = {                        68,
   10,  -48,    0,  -17,  -32,    0,   34,  -24,    0,    0,
    0,   61,    0,
};
#define YYTABLESIZE 300
static const YYINT yytable[] = {                         37,
   19,   45,   15,   62,   18,   12,   21,   35,   42,   22,
   69,   26,   13,   43,   37,   27,    8,   46,    4,   71,
   63,   36,   44,   28,   50,   13,   61,   70,    6,   31,
   32,    1,    9,   29,   38,   11,    2,    3,   16,   30,
   39,   17,   18,   19,    6,    7,   47,    8,    9,   54,
   55,   48,   56,   57,   29,   29,   51,   29,   29,   31,
   31,   52,   31,   31,   64,   65,   66,   67,   53,   59,
   60,    1,   15,   25,   49,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   19,    0,
   15,    0,   18,   19,   19,   15,   15,   18,   18,    0,
    0,   19,   37,   15,    8,   18,    4,   37,   37,    8,
    8,    4,    4,   13,    0,   37,    6,    0,   13,   13,
    9,    6,    6,   11,    0,    9,    9,    0,   11,   11,
};
static const YYINT yycheck[] = {                         24,
    0,   34,    0,   52,    0,  259,  259,  258,  258,  271,
   59,  259,    3,  263,    0,  257,    0,   35,    0,   68,
   53,  272,  272,  257,   42,    0,   51,   60,    0,   20,
  271,  258,    0,  257,   25,    0,  263,  264,  257,  257,
  271,  260,  261,  262,  269,  270,  257,  272,  273,  269,
  270,  272,  272,  273,  269,  270,  259,  272,  273,  269,
  270,  257,  272,  273,  265,  266,  267,  268,  259,  257,
  259,    0,    5,   13,   41,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,   -1,
  258,   -1,  258,  263,  264,  263,  264,  263,  264,   -1,
   -1,  271,  258,  271,  258,  271,  258,  263,  264,  263,
  264,  263,  264,  258,   -1,  271,  258,   -1,  263,  264,
  258,  263,  264,  258,   -1,  263,  264,   -1,  263,  264,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 273
#define YYUNDFTOKEN 289
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ASSIGNOP","IFRSW","COLON",
"EXCLAMATION","LESS","GREATER","ELSE","ELIF","MINUSOP","PLUSOP","MULTOP",
"DIVIDEOP","INTEGER","FLOAT","TAB","VARIABLE","STRING",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : statement",
"program : statement program",
"statement : IFRSW if_case COLON if_body",
"statement : IFRSW if_case COLON",
"statement : ELIF elif_case COLON elif_body",
"statement : ELIF elif_case COLON",
"statement : ELSE COLON else_body",
"statement : ELSE COLON",
"if_body : if_statement",
"if_body : if_statement if_body",
"elif_body : elif_statement",
"elif_body : elif_statement elif_body",
"else_body : else_statement",
"else_body : else_statement else_body",
"if_statement : TAB VARIABLE ASSIGNOP if_expression",
"if_statement : TAB IFRSW if_case COLON if_body",
"if_statement : TAB ELSE COLON else_body",
"elif_statement : TAB VARIABLE ASSIGNOP if_expression",
"else_statement : TAB VARIABLE ASSIGNOP if_expression",
"else_statement : TAB IFRSW if_case COLON if_body",
"if_case : var_type case_type var_type",
"elif_case : var_type case_type var_type",
"var_type : VARIABLE",
"var_type : INTEGER",
"var_type : FLOAT",
"var_type : STRING",
"case_type : ASSIGNOP ASSIGNOP",
"case_type : EXCLAMATION ASSIGNOP",
"case_type : LESS",
"case_type : LESS ASSIGNOP",
"case_type : GREATER",
"case_type : GREATER ASSIGNOP",
"if_expression : INTEGER",
"if_expression : FLOAT",
"if_expression : STRING",
"if_expression : VARIABLE",
"if_expression : if_expression operator if_expression",
"operator : MINUSOP",
"operator : PLUSOP",
"operator : MULTOP",
"operator : DIVIDEOP",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 458 "ifpart.y"


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
#line 357 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 3:
#line 51 "ifpart.y"
	{
		cout<<"A"<<endl;
		finalOutput+= ifVar + ifInIf + elseInIf + "\t}\n";
		ifVar="";
		elseInIf="";
	}
break;
case 4:
#line 59 "ifpart.y"
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block"<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 5:
#line 65 "ifpart.y"
	{
		cout<<"B"<<endl;
		finalOutput+= elifVar + "\t}\n";
		elifVar="";
	}
break;
case 6:
#line 72 "ifpart.y"
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block"<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 7:
#line 78 "ifpart.y"
	{
		cout<<"C"<<endl;
		finalOutput+= "\telse\n\t{\n" + elseVar + "\t}\n";
		elseVar="";
	}
break;
case 8:
#line 85 "ifpart.y"
	{
		cout<<"error in line "<<linenum<<": at least one line should be inside if/elif/else block"<<endl;
		exit (EXIT_FAILURE);
	}
break;
case 15:
#line 111 "ifpart.y"
	{
		cout<<"D "<<yystack.l_mark[-2].str<<endl;
		ifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[-2].str)+"_int" || itr->first == string(yystack.l_mark[-2].str)+"_flt" || itr->first == string(yystack.l_mark[-2].str)+"_str")
			{
				ifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if(yystack.l_mark[0].number == 1)
			{
				values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
				ifVar+= "\t" + string(yystack.l_mark[-2].str) + "_int";
			}
			else if(yystack.l_mark[0].number == 2)
			{
				values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
				ifVar+= "\t" + string(yystack.l_mark[-2].str) + "_flt";
			}
			else if(yystack.l_mark[0].number == 0)
			{
				values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
				ifVar+= "\t" + string(yystack.l_mark[-2].str) + "_str";
			}
		}
		ifVar+= " = " + var + ";\n";
		var="";
	}
break;
case 16:
#line 147 "ifpart.y"
	{
		cout<<"E"<<endl;
		ifInIf+= ifVar + elseInIf + "\t}\n";
		ifVar="";
		elseInIf="";
	}
break;
case 17:
#line 155 "ifpart.y"
	{
		cout<<"F"<<endl;
		cout<<ifInElse<<endl;
		elseInIf+= "\telse\n\t{\n" + elseVar + ifInElse + "\t}\n";
		elseVar="";
		ifInElse="";
	}
break;
case 18:
#line 166 "ifpart.y"
	{
		cout<<"G "<<yystack.l_mark[-2].str<<endl;
		elifVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[-2].str)+"_int" || itr->first == string(yystack.l_mark[-2].str)+"_flt" || itr->first == string(yystack.l_mark[-2].str)+"_str")
			{
				elifVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if(yystack.l_mark[0].number == 1)
			{
				values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
				elifVar+= "\t" + string(yystack.l_mark[-2].str) + "_int";
			}
			else if(yystack.l_mark[0].number == 2)
			{
				values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
				elifVar+= "\t" + string(yystack.l_mark[-2].str) + "_flt";
			}
			else if(yystack.l_mark[0].number == 0)
			{
				values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
				elifVar+= "\t" + string(yystack.l_mark[-2].str) + "_str";
			}
		}
		elifVar+= " = " + var + ";\n";
		var="";
	}
break;
case 19:
#line 204 "ifpart.y"
	{	
		cout<<"H "<<yystack.l_mark[-2].str<<endl;
		elseVar+= "\t";
		bool check=0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[-2].str)+"_int" || itr->first == string(yystack.l_mark[-2].str)+"_flt" || itr->first == string(yystack.l_mark[-2].str)+"_str")
			{
				elseVar+= "\t" + itr->first;
				check=1;
				break;
			}
		}
		if(check == 0)
		{
			if(yystack.l_mark[0].number == 1)
			{
				values[string(yystack.l_mark[-2].str)+"_int"] = yystack.l_mark[0].number;
				elseVar+= "\t" + string(yystack.l_mark[-2].str) + "_int";
			}
			else if(yystack.l_mark[0].number == 2)
			{
				values[string(yystack.l_mark[-2].str)+"_flt"] = yystack.l_mark[0].number;
				elseVar+= "\t" + string(yystack.l_mark[-2].str) + "_flt";
			}
			else if(yystack.l_mark[0].number == 0)
			{
				values[string(yystack.l_mark[-2].str)+"_str"] = yystack.l_mark[0].number;
				elseVar+= "\t" + string(yystack.l_mark[-2].str) + "_str";
			}
		}
		elseVar+= " = " + var + ";\n";
		var="";
	}
break;
case 20:
#line 240 "ifpart.y"
	{
		cout<<"I"<<endl;
		cout<<ifVar<<endl;
		ifInElse+= ifVar + "\t}\n";
		ifVar="";
	}
break;
case 21:
#line 250 "ifpart.y"
	{
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number == 9 || yystack.l_mark[0].number == 9)
		{
			ifVar+= "\tif( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number != 0 && yystack.l_mark[0].number != 0)
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
break;
case 22:
#line 276 "ifpart.y"
	{
		if(elseNum != 0)
		{
			cout<<"elif after else in line " << linenum << endl;
			exit (EXIT_FAILURE);
		}
		
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)
		{
			elifVar+= "\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number == 9 || yystack.l_mark[0].number == 9)
		{
			elifVar+= "\telse if( " + ifVarInside + " )\n\t{\n";
			ifVarInside="";
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number != 0 && yystack.l_mark[0].number != 0)
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
break;
case 23:
#line 309 "ifpart.y"
	{
		bool check = 0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[0].str)+"_int" || itr->first == string(yystack.l_mark[0].str)+"_flt" || itr->first == string(yystack.l_mark[0].str)+"_str")
			{
				ifVarInside+=itr->first;
				yyval.number=itr->second;
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			ifVarInside+=string(yystack.l_mark[0].str);
			yyval.number=9;
			
		}
	}
break;
case 24:
#line 330 "ifpart.y"
	{
		ifVarInside+=string(yystack.l_mark[0].str);
		yyval.number=1;
	}
break;
case 25:
#line 336 "ifpart.y"
	{
		ifVarInside+=string(yystack.l_mark[0].str);
		yyval.number=2;
	}
break;
case 26:
#line 342 "ifpart.y"
	{
		ifVarInside+=string(yystack.l_mark[0].str);
		yyval.number=0;
	}
break;
case 27:
#line 350 "ifpart.y"
	{
		ifVarInside+= " == ";
	}
break;
case 28:
#line 355 "ifpart.y"
	{
		ifVarInside+= " != ";
	}
break;
case 29:
#line 360 "ifpart.y"
	{
		ifVarInside+= " < ";
	}
break;
case 30:
#line 365 "ifpart.y"
	{
		ifVarInside+= " <= ";
	}
break;
case 31:
#line 370 "ifpart.y"
	{
		ifVarInside+= " > ";
	}
break;
case 32:
#line 375 "ifpart.y"
	{
		ifVarInside+= " >= ";
	}
break;
case 33:
#line 382 "ifpart.y"
	{
		yyval.number=1;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 34:
#line 388 "ifpart.y"
	{
		yyval.number=2;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 35:
#line 394 "ifpart.y"
	{
		yyval.number=0;
		var+=string(yystack.l_mark[0].str);
	}
break;
case 36:
#line 400 "ifpart.y"
	{
		bool check = 0;
		for (itr = values.begin(); itr != values.end(); ++itr)
		{	
			if(itr->first == string(yystack.l_mark[0].str)+"_int" || itr->first == string(yystack.l_mark[0].str)+"_flt" || itr->first == string(yystack.l_mark[0].str)+"_str")
			{
				yyval.number = itr->second;
				var+=itr->first;
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			var+=string(yystack.l_mark[0].str);	
		}
	}
break;
case 37:
#line 419 "ifpart.y"
	{
		if(yystack.l_mark[-2].number == yystack.l_mark[0].number)	/*control type mach*/
		{
			yyval.number=yystack.l_mark[-2].number;
		}
		else if(yystack.l_mark[-2].number != yystack.l_mark[0].number && yystack.l_mark[-2].number == 0 || yystack.l_mark[0].number == 0)
		{
			cout<<"type mismatch in line "<<linenum<<endl;
			exit (EXIT_FAILURE);
		}
		else
		{
			yyval.number=2;
		}
	}
break;
case 38:
#line 438 "ifpart.y"
	{
		var+=" - ";
	}
break;
case 39:
#line 443 "ifpart.y"
	{
		var+=" + ";
	}
break;
case 40:
#line 448 "ifpart.y"
	{
		var+=" * ";
	}
break;
case 41:
#line 453 "ifpart.y"
	{
		var+=" / ";
	}
break;
#line 963 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
