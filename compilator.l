%{
    #include <stdio.h>
    #include "y.tab.h"
%}

%option noyywrap
%%



"int"|"float"|"char"|"string"|"bool" {yylval.strv=strdup(yytext);return TIP;}
"void" {yylval.strv=strdup(yytext);return VOID;}


"begin_p" {return BEGINP;}
"end_p" {return ENDP;}

"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}



"class" {return CLASS;}
"public"|"private" {return CLASS_TIP;}

"true"|"false" {return BOOL_VARIABLE;}

"Eval" {return EVAL;}
"Print" {return PRINT;}
"TyepOf" {return TYPEOF;}

"{" {return LB;}
"}" {return RB;}

"&&" {return AND;}
"||" {return OR;}


"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}


"<" {return LESS;}
">" {return GREAT;}
"<=" {return LESSEQ;}
">=" {return GREATEQ;}
"==" {return EQ;}


"array" {yylval.strv=strdup(yytext);return ARRAY;}

[a-zA-Z][a-zA-Z0-9]* {yylval.strv=strdup(yytext); return ID;}
0|[1-9][0-9]* {yylval.intv=atoi(yytext);return CONST_INT;}
(0|[1-9][0-9]*)\.[0-9]+ {yylval.strv=strdup(yytext); return CONST_FLOAT;}
\"[ a-zA-Z]+\" {yylval.strv=strdup(yytext);return CONST_STRING;}
\'[a-zA-Z]\' {yylval.strv=strdup(yytext); return CHAR;}




[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
