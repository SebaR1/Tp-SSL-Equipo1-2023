%option noyywrap
%{
#include <stdio.h>
#include "Scanner.h"
extern Token token;
%}
DIGITS [0-9]+
SPACE [ \t]+
%%

{DIGITS}              |
{DIGITS}"."{DIGITS}?  |
{DIGITS}?"."{DIGITS}   {token.val = atof(yytext); token.type=Number; return true;}

[+]     {token.type = '+'; return true;} 
[*]     {token.type = '*'; return true;} 
[-]     {token.type = '-'; return true;}
[/]     {token.type = '/'; return true;}
[\n]    {token.type = PopResult; return true;}  
{SPACE}   {token.type = ' '; return true;} // Espacios en blanco y tabulaciones.
[EOF]   {return false;}
.       {token.type = LexError; return true;}
%%