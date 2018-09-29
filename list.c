#include "list.h"

#include <stdlib.h>

List List_create(void) {
	List l = NULL;
	return l;
}

void List_destroy(List l) {
	for(List q = l; q != NULL; q = l) {
		l = (List) l->next;
		free(q->name);
		free(q);
	}
}

List List_insert(List l, void * value, str name) {
	int i;
	List q = malloc(sizeof(Node));
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
	q->next = (void *) l;
	return q;
}

List_Pack List_query_pointer(List l, str name) {
	List_Pack ret;
	ret.l = NULL;
	ret.v = NULL;
	List q = NULL;
	for(; l != NULL; q = l, l = (List) l->next) {
		for(int i = 0; name[i] != '\0'; i++) {
			if(name[i] != l->name[i]) break;
		}
		goto found;
	}
	return ret;
found:	ret.v = (void *) l;
	ret.l = q;
	return ret;
}

void * List_query(List l, str name) {
	List_Pack p = List_query_pointer(l, name);
	if(p.v == NULL) return NULL;
	return ((List) p.v)->value;
}

List_Pack remove(List l, str name) {
	List_Pack pack;
	pack.l = l;
	pack.v = NULL;
	List_Pack ret = List_query_pointer(l, name);
	if(ret.v == NULL) /*Could not found*/
		goto done;
	if(ret.l == NULL) { /*The first value*/
		pack.l = ((List) ret.v)->next;
		pack.v = ((List) ret.v)->value;
	}
	ret.l->next = ((List) ret.v)->next;
	pack.v = ((List) ret.v)->value;
	free(((List) ret.v)->name);
	free(ret.v);
done:	return pack;
}

