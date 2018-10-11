/* list.c - by Vitor Silva */

#include "list.h"

#include <stdlib.h>

typedef struct {
	Node * l;
	Node * v;
} List_Pack;

List * List_create(void) {
	List * l = malloc(sizeof(List));
	l->node = NULL;
	l->size = 0;
	return l;
}

void List_free(List * l) {
	for(Node * q = l->node, * g; q != NULL; q = g) {
		g = (Node *) q->next;
		free(q->name);
		free(q);
	}
	free(l);
}

Node * List_insert(List * l, void * value, str name) {
	int i;
	Node * q = malloc(sizeof(Node));
	if(q == NULL) return NULL;
	for(i = 0; name[i] != '\0'; i++);
	q->name = malloc(sizeof(char) * (i + 1));
	if(q->name == NULL) {
		free(q);
		return NULL;
	}
	for(i = 0; name[i] != '\0'; i++) q->name[i] = name[i];
	q->name[i] = '\0';
	q->value = value;
	q->next = l->node;
	l->node = q;
	l->size++;
	return q;
}

// Fix this buggy bit of code
static List_Pack List_query_pointer(List * l, str name) {
	List_Pack ret;
	ret.l = NULL;
	ret.v = NULL;
	Node * q = NULL;
	Node * g = l->node;
	int i;
	for(; g != NULL; g = (Node *) g->next) {
		Bool b = 1;
		for(i = 0; name[i] != '\0' || g->name[i] != '\0'; i++) {
			if(name[i] != g->name[i]) b = 0;
		}
		if(name[i] != g->name[i]) b = 0; /*Check stuff likes can and cant*/
		if(b) goto found;
		q = g;
	}
	return ret;
found:
	ret.v = g;
	ret.l = q;
	return ret;
}

void * List_query(List * l, str name) {
	List_Pack p = List_query_pointer(l, name);
	if(p.v == NULL) return NULL;
	return (p.v)->value;
}

void * List_remove(List * l, str name) {
	void * pack = NULL;
	List_Pack ret = List_query_pointer(l, name);
	if(ret.v == NULL) /*Could not found*/
		goto done;
	if(ret.l == NULL) { /*The first value*/
		l->node = (ret.v)->next;
	} else {
		ret.l->next = ((Node *) ret.v)->next;
	}
	pack = ret.v->value;
	free(ret.v->name);
	free(ret.v);
done:	return pack;
}

