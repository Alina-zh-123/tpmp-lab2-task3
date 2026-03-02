all: main

main: main.o date.o
	gcc -o main main.o date.o

main.o: main.c
	gcc -c main.c

date.o: date.c
	gcc -c date.c

clean:
	rm -f *.o main
