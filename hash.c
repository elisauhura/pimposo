/* Hash.c - By Lucas Sobrinho*/

#include "hash.h"
#include "list.h"

#include <stdlib.h>

int hash_function(str key) {
	return 0;
}

TabSim TabSim_create(int size) {
	TabSim t = malloc(sizeof(TabSim));
	t->size = size;

	t->entries = malloc(size*sizeof(List));
	for(int i; i<size; i++){
		t->entries[i] = List_create();
	}

	return t;
}

void TabSim_destroy(TabSim t) {
	for(int i; i<t->size; i++){
		List_destroy(t->entries[i]);
	}
	free(t->entries);
	free(t);
}

Bool TabSim_insert(TabSim t, str key, void * value) {
	int pos = hash_function(key) % t->size;
	if (TabSim_query(t, key)==NULL){
		return 1;
	}
	List_insert(t->entries[pos], value, key);
	return 0;

}

Element * TabSim_query(TabSim t, str key) {
	return NULL;
}

Bool TabSim_remove(TabSim t, str key) {
	return 0;
}
