GCC_VERSION = c2x
CC = gcc
CFLAGS = -c

all: 


Calculator.o: Calculator.c
	$(CC) $(CFLAGS) Calculator.c -o Calculator.o -std=$(GCC_VERSION)

Lex.l: Lex.c	
	flex -o Lex.c Lex.l

Lex.o: Lex.c
	$(CC) $(CFLAGS) Lex.c -o Lex.o
 
StackOfDoublesModule.o: StackOfDoublesModule.c
	$(CC) $(CFLAGS) StackOfDoublesModule.c -o StackOfDoublesModule.o

programa1: Calculator.o Lex.o StackOfDoublesModule.o 
	$(CC) Calculator.o Lex.o StackOfDoublesModule.o -o programa1 -std=$(GCC_VERSION) -lfl


run1: programa1
	./programa1 < expresiones.txt


clean:
	rm -f *.o programa1 Lex.c


