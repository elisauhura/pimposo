CC=gcc
Flags=-Wall -Werror

main: list hash element
	$(CC) main.c list.o hash.o element.o $(Flags) -o pimp

list:
	$(CC) -c list.c $(Flags) -o list.o

hash:
	$(CC) -c hash.c $(Flags) -o hash.o

element:
	$(CC) -c element.c $(Flags) -o element.o
