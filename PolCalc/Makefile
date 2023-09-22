GCC_VERSION = c2x
CC = gcc
CFLAGS = -c

all: 


Calculator.o: Calculator.c
	$(CC) $(CFLAGS) Calculator.c -o Calculator.o -std=$(GCC_VERSION)

Scanner.o: Scanner.c
	$(CC) $(CFLAGS) Scanner.c -o Scanner.o
 
StackOfDoublesModule.o: StackOfDoublesModule.c
	$(CC) $(CFLAGS) StackOfDoublesModule.c -o StackOfDoublesModule.o

programa1: Calculator.o Scanner.o StackOfDoublesModule.o 
	$(CC) Calculator.o Scanner.o StackOfDoublesModule.o -o programa1 -std=$(GCC_VERSION)


run1: programa1
	./programa1 < test.txt


clean:
	rm -f *.o 

