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

test_hash: hash
	$(CC) hash.test.c hash.o $(Flags) -o test_hash
	./test_hash
	rm test_hash

element:
	$(CC) -c element.c $(Flags) -o element.o

test_element: element
	$(CC) element.test.c element.o $(Flags) -o test_element
	./test_element
	rm test_element

test_all: test_element test_hash test_list
	$(CC) all.test.c all.o $(Flags) -o test_all
	./test_all
	rm test_all

listmods:
	ls | grep .c | sed -e s/.c//g

clean:
	rm *.o