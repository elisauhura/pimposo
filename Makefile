CC=gcc
Flags=-Wall -Werror

list:
	$(CC) -c list.c $(Flags) -o list.o

test_list: list
	$(CC) list.test.c list.o $(Flags) -o test_list
	./test_list
	rm test_list

hash:
	$(CC) -c hash.c $(Flags) -o hash.o

element:
	$(CC) -c element.c $(Flags) -o element.o

test_element: element
	$(CC) element.test.c element.o $(Flags) -o test_element
	./test_element
	rm test_element

listmods:
	ls | grep .c | sed -e s/.c//g