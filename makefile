CC = gcc
CFLAGS = -Wall -Wextra -g

all: quickSort clean

quickSort: quickSort.o stack.o
	$(CC) $(CFLAGS) -o quickSort quickSort.o stack.o

quickSort.o: quickSort.c stack.h
	$(CC) $(CFLAGS) -c quickSort.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o

