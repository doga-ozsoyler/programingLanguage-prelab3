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
