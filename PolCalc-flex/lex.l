%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include "Scanner.h" 
%}





DIGITS [0-9]+

%%

{DIGITS}              |
{DIGITS}"."{DIGITS}?  |
{DIGITS}"?."{DIGITS}   return Number;

[-][0-9]+ {
    yylval.val = -atof(yytext + 1); // Convierte la cadena en un número negativo.
    return NUMBER;
}

[+]     return ADDITION; 
[*]     return MULTIPLICATION; 
[-]     return SUBTRACTION; 
[/]     return DIVISION; 
[\n]    return POP_RESULT; 
[ \t]   ; // Espacios en blanco y tabulaciones.

.  return LEX_ERROR;


%%