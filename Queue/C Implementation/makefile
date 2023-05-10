

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

run: clean main
	clear
	./main.exe

main: main.o queue.o
	$(CC) $(CFLAGS) main.o queue.o -o main.exe

main.o: main.c queue.h
	$(CC) $(CFLAGS) -c main.c -o main.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

clean:
	rm queue.o
	rm main.o
