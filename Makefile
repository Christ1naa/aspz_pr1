CC = gcc
CFLAGS = -Wall -O2

all: main

main: main.o erf_module.o
	$(CC) $(CFLAGS) -o main main.o erf_module.o -lm

main.o: main.c erf_module.h
	$(CC) $(CFLAGS) -c main.c

erf_module.o: erf_module.c erf_module.h
	$(CC) $(CFLAGS) -c erf_module.c

clean:
	rm -f *.o main
