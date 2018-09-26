/* List.h - by Vitor Silva */

#include "type.h"

typedef struct {
	void * value;
	Node * next;
} Node

typedef Node * List;

List List_create();
void List_destroy(List l);
List List_insert(List l, void * value); /*Return pointer to node(value) or NULL*/
void * List_query(List l, str name);
void * remove(List l, void * value);
