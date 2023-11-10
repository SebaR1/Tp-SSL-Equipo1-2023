%option noyywrap
%{
#include <stdio.h>
#include "Calculator.tab.h"
%}

DIGITS [0-9]+
SPACE [ \t]+

%%

"-"?{DIGITS}              |
"-"?{DIGITS}"."{DIGITS}?  |
"-"?{DIGITS}?"."{DIGITS}   {yylval.real = atof(yytext); return NUMBER;}

[+]     {return ADDITTION;} 
[*]     {return MULTIPLICATION;} 
[-]     {return SUBSTRACTION; }
[/]     {return DIVISION; }
[\n]    {return POP;}  
{SPACE} {return SPACE; } // Espacios en blanco y tabulaciones.
.       {return LEXERROR;}

%%


