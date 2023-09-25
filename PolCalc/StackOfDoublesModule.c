#include "StackofDoublesModule.h"
#include "stdio.h"

unsigned static sp=0;
stackItem static stack[MAXVAL];

bool isEmpty(){
    return sp == 0;
}

bool isFull(){
    return sp == MAXVAL-1;
}

void push(stackItem token){
    if(isFull()){
        printf("error de pila llena");
    } else {
        stack[sp] = token;
        ++sp;
    }
}

stackItem pop(){
    if (!isEmpty ()) { 
        return stack[--sp];
    }
    else printf("error de pila vacia");
    return 0.0;
}
