/* List.h - by Vitor Silva */

#ifndef LIST_H
#define LIST_H

#include "type.h"

typedef struct {
	void * value;
	str name;
	void * next;
} Node;

typedef struct{
	Node * node;
	int size;
} List;

List * List_create(void);
void List_free(List * l);
Node * List_insert(List * l, void * value, str name); /*Return pointer to node(value) or NULL, copies str*/
void * List_query(List * l, str name);
void * List_remove(List * l, str name); 

#endif