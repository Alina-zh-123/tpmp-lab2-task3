CFLAGS = -I./src

main: src/main.o src/date.o
	gcc -o main src/main.o src/date.o

src/main.o: src/main.c
	gcc $(CFLAGS) -c src/main.c -o src/main.o

src/date.o: src/date.c
	gcc $(CFLAGS) -c src/date.c -o src/date.o
