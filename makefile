CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

program: IntVector.o main.o
$(CC) -o program IntVector.o main.o

IntVector.o: IntVector.c intVector.h
$(CC) $(CFLAGS) -c IntVector.c

main.o: main.c intVector.h
$(CC) $(CFLAGS) -c main.c

clean:
rm -f program *.o