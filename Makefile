CFLAGS = -I./src

main: obj/main.o obj/date.o
    gcc -o main obj/main.o obj/date.o

obj/main.o: src/main.c
    mkdir -p obj
    gcc $(CFLAGS) -c src/main.c -o obj/main.o

obj/date.o: src/date.c
    mkdir -p obj
    gcc $(CFLAGS) -c src/date.c -o obj/date.o
