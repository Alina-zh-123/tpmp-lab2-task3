CC = gcc
CFLAGS = -I./src

main: src/main.o src/date.o
	$(CC) -o main src/main.o src/date.o

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/date.o: src/date.c
	$(CC) $(CFLAGS) -c src/date.c -o src/date.o

clean:
	rm -f src/*.o main
