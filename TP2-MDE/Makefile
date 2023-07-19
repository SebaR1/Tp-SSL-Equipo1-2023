CC = gcc
CFLAGS = -c
SLASH = ./

all: programa1 programa2

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

histograma-1-enum-switch.c.o: histograma-1-enum-switch.c
	$(CC) $(CFLAGS) histograma-1-enum-switch.c -o histograma-1-enum-switch.o

histograma-2-goto.o: histograma-2-goto.c
	$(CC) $(CFLAGS) histograma-2-goto.c -o histograma-2-goto.o

graficador.o: graficador.c
	$(CC) $(CFLAGS) graficador.c -o graficador.o

programa1: main.o histograma-1-enum-switch.o graficador.o 
	$(CC) main.o histograma-1-enum-switch.o graficador.o -o programa1

programa2: main.o histograma-2-goto.o graficador.o
	$(CC) main.o histograma-2-goto.o graficador.o -o programa2

run1: programa1
	./programa1 < archivo.txt

run2: programa2
	./programa2 < archivo.txt

clean:
	rm -f main.o histograma-1-enum-switch.o graficador.o histograma-2-goto.o programa1 programa2