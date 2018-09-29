/* List.h - by Vitor Silva */

#include "type.h"

typedef struct {
	void * value;
	str name;
	void * next;
} Node;

typedef Node * List;

typedef struct {
	List l;
	void * v;
} List_Pack;

List List_create(void);
void List_destroy(List l);
List List_insert(List l, void * value, str name); /*Return pointer to node(value) or NULL, copies str*/
void * List_query(List l, str name);
List_Pack remove(List l, str name); /* Needs to return a new List, because the first node may be removed, return NULL if nout found item to be removed*/
