all: example;
example: main auto_free
	gcc -o example.exe ./obj/main.o ./obj/auto_free.o
main:
	gcc -c main.c -o ./obj/main.o
auto_free:
	gcc -c auto_free.c -o ./obj/auto_free.o