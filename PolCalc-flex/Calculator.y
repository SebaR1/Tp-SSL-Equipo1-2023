%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
void yyerror(const char *s);
%}

%union 
{
    double real;
}

%token <real> NUMBER
%token ADDITTION
%token SUBSTRACTION
%token MULTIPLICATION
%token DIVISION
%token POP
%token SPACE
%token TAB
%token LEXERROR
%type <real> expr
%type <spacer> sp
%start Inicio

%%

Inicio: expr

expr: NUMBER { $$ = $1; }
    | expr sp expr sp ADDITTION { $$ = $1 + $3; }
    | expr sp expr sp SUBSTRACTION { $$ = $1 - $3; }
    | expr sp expr sp MULTIPLICATION { $$ = $1 * $3; }
    | expr sp expr sp DIVISION { if ($3 != 0) $$ = $1 / $3; else { printf("Error, no se puede dividir por cero, replantéese sus elecciones de vida\n"); } }
    | expr POP {printf("\nResultado: %.2f\n", $1);}

sp: SPACE {;}
  | TAB {;}

%%

int main(void){
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    printf("\n%s\n", s);
}
