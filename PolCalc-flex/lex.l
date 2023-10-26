%option noyywrap

%{
#include <stdio.h>
#include "Scanner.h" 
%}


Token t;
DIGITS [0-9]+

%%

[-]?{DIGITS}              |
[-]?{DIGITS}"."{DIGITS}?  |
[-]?{DIGITS}"?."{DIGITS}   {((t.val = atof(yytext), t.type=Number),return true);}






[+]     (t.type = '+'); 
[*]     (t.type = '*'); 
[-]     (t.type = '-'); 
[/]     (t.type = '/'); 
[\n]    (t.type = PopResult,return true); 
[ \t]   ; // Espacios en blanco y tabulaciones.
[EOF]   (return false);

.       return LEX_ERROR;


%%