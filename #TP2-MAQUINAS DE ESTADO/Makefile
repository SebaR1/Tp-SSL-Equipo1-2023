CC = gcc
CFLAGS = -c

all: programa

main.o: main.c
    $(CC) $(CFLAGS) main.c -o main.o

histograma-1-enum-switch.c.o: histograma-1-enum-switch.c
    $(CC) $(CFLAGS) histograma-1-enum-switch.c -o histograma-1-enum-switch.o

programa: main.o histograma-1-enum-switch.o
	$(CC) main.o histograma-1-enum-switch.o -o programa

clean:
    rm -f main.o histograma-1-enum-switch.o programa