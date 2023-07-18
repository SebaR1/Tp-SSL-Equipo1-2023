CC = gcc
CFLAGS = -c
SLASH = ./

all: programa

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o

histograma-1-enum-switch.c.o: histograma-1-enum-switch.c
	$(CC) $(CFLAGS) histograma-1-enum-switch.c -o histograma-1-enum-switch.o

graficador.o: graficador.c
	$(CC) $(CFLAGS) graficador.c -o graficador.o

programa: main.o histograma-1-enum-switch.o graficador.o 
	$(CC) main.o histograma-1-enum-switch.o graficador.o -o programa

run: programa
	./programa < archivo.txt

clean:
	rm -f main.o histograma-1-enum-switch.o graficador.o programa