#include "scanner.h"
#include <ctype.h>
#include <stdio.h>

#define MAXTAMANIO 10

bool getNextToken(Token *t ){
    char lexeme[MAXTAMANIO];

    int c, i;

    while((lexeme[0] = c = getchar()) == ' ' || c == '\t'){
        
        lexeme[1] = '\0';

        if (c == EOF){
            return false;
        }

        if ((!isdigit(c) && c != '.')){
            if ((lexeme[0] = c = getchar()) == '-'){
                if (isdigit(c = getchar())) 
                goto numero;
                
            }
            t->type = c;
            t->val = 0;
            return true;
        }
        numero:
        i = 0;
        while(isdigit(lexeme[++i] = c = getchar()));
        if (c == '.'){
            while (isdigit(lexeme[++i] = c = getchar()));
        }

        lexeme[i] = '\0';
        t->type = Number; 
        t->val = atof(lexeme);
        
    }

     if(c != EOF){
            ungetc(c,stdin);
        }

    return true;
}

/*while (isdigit(c)){
            while(isdigit(lexeme[++i] = c = getchar()));
            if (c == '.'){
                while (isdigit(lexeme[++i] = c = getchar()))
                ;
                t->type = Number;
                t->val = atof(lexeme);        

                return true;
            }
        }
        */