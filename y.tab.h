#define ASSIGNOP 257
#define MINUSOP 258
#define PLUSOP 259
#define MULTOP 260
#define DIVIDEOP 261
#define INTEGER 262
#define FLOAT 263
#define VARIABLE 264
#define STRING 265
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
extern YYSTYPE yylval;
