GCC_VERSION = c2x
CC = gcc
CFLAGS = -c

all: programa1 programa2 programa3 programa4 programaTest


main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o -std=$(GCC_VERSION)

test.o: test.c
	$(CC) $(CFLAGS) test.c -o test.o
 
histograma-1-enum-switch.c.o: histograma-1-enum-switch.c
	$(CC) $(CFLAGS) histograma-1-enum-switch.c -o histograma-1-enum-switch.o

histograma-2-goto.o: histograma-2-goto.c
	$(CC) $(CFLAGS) histograma-2-goto.c -o histograma-2-goto.o -std=$(GCC_VERSION)

histograma-3-rec.o: histograma-3-rec.c
	$(CC) $(CFLAGS) histograma-3-rec.c -o histograma-3-rec.o -std=$(GCC_VERSION)

histograma-4-x.o: histograma-4-x.c
	$(CC) $(CFLAGS) histograma-4-x.c -o histograma-4-x.o -std=$(GCC_VERSION)

graficador.o: graficador.c
	$(CC) $(CFLAGS) graficador.c -o graficador.o

programa1: main.o histograma-1-enum-switch.o graficador.o 
	$(CC) main.o histograma-1-enum-switch.o graficador.o -o programa1 -std=$(GCC_VERSION)

programa2: main.o histograma-2-goto.o graficador.o
	$(CC) main.o histograma-2-goto.o graficador.o -o programa2 -std=$(GCC_VERSION)

programa3: main.o histograma-3-rec.o graficador.o
	$(CC) main.o histograma-3-rec.o graficador.o -o programa3 -std=$(GCC_VERSION)

programa4: main.o histograma-4-x.o graficador.o
	$(CC) main.o histograma-4-x.o graficador.o -o programa4 -std=$(GCC_VERSION)

programaTest1: test.o histograma-1-enum-switch.o graficador.o 
	$(CC) test.o histograma-1-enum-switch.o graficador.o -o programaTest1

programaTest2: test.o histograma-2-goto.o graficador.o
	$(CC) test.o histograma-2-goto.o graficador.o -o programaTest2 -std=$(GCC_VERSION)
	
programaTest3: test.o histograma-3-rec.o graficador.o
	$(CC) test.o histograma-3-rec.o graficador.o -o programaTest3 -std=$(GCC_VERSION)
	
programaTest4: test.o histograma-4-x.o graficador.o
	$(CC) test.o histograma-4-x.o graficador.o -o programaTest4 -std=$(GCC_VERSION)
	
run1: programa1
	./programa1 < archivo.txt

run2: programa2
	./programa2 < archivo.txt

run3: programa3
	./programa3 < archivo.txt

run4: programa4	
	./programa4 < archivo.txt

runTest1: programaTest1
	./programaTest1

runTest2: programaTest2
	./programaTest2

runTest3: programaTest3
	./programaTest3

runTest4: programaTest4
	./programaTest4

clean:
	rm -f *.o programa1 programa2 programa3 programa4 programaTest1

