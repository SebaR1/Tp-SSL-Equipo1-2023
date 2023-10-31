GCC_VERSION = c2x
CC = gcc
CFLAGS = -c
DFLAGS = -d
BB = bison

all: 


Calculator.tab.c: Calculator.y
	$(BB) $(DFLAGS) Calculator.y 

Calculator.tab.o: Calculator.tab.c
	$(CC) $(CFLAGS) Calculator.tab.c -o Calculator.tab.o -std=$(GCC_VERSION)

Lex.c: Lex.l	
	flex -o Lex.c Lex.l

Lex.o: Lex.c
	$(CC) $(CFLAGS) Lex.c -o Lex.o

programa1: Calculator.tab.o Lex.o 
	$(CC) Calculator.tab.o Lex.o -o programa1 -std=$(GCC_VERSION)


run1: programa1
	./programa1 < expresiones.txt

clean:
	rm -f *.o programa1 Lex.* Calculator.tab.*


	