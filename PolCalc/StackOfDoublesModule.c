#include "StackofDoublesModule.h"

int sp=0;
double static stack[MAXVAL];

bool isEmpty(){
    return sp == 0;
}

bool isFull(){
    return sp == MAXVAL-1;
}

void push(double token){
    if(isFull()){
        return printf("error de pila llena");
    } else {
        stack[++sp] = token;
    }
}

double pop(){
    if (!isEmpty) return stack[--sp];
    else printf("error de pila vacia");
    return 0.0;
}
