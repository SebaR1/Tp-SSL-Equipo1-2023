%{
#include <stdio.h>
#include <stdlib.h>
#include "Scanner.h"
int yylex(void);
void yyerror(const char *s);
extern char *yytext;
Token token;
%}

%union 
{
    float real;
}

%token <real> NUMBER
%token ADDITTION
%token SUBSTRACTION
%token MULTIPLICATION
%token DIVISION
%token POP
%type <real> expr
%start Inicio

%%

Inicio: expr

expr: NUMBER { $$ = $1; }
    | expr expr ADDITTION { $$ = $1 + $2; }
    | expr expr SUBSTRACTION { $$ = $1 - $2; }
    | expr expr MULTIPLICATION { $$ = $1 * $2; }
    | expr expr DIVISION { if ($2 != 0) $$ = $1 / $2; else { printf("Error, no se puede dividir por cero, replantéese sus elecciones de vida\n"); } }
    | expr POP {printf("resultado: %.2f\n", $1);}

%%

int main(void){
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("\n%s\n", s);
}

int yywrap(){
    return 1;
}