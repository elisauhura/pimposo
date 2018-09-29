/* Hash.h - by Vitor Silva */

#include "type.h"

typedef struct {
	str key;
	void * value;
} Sim;

typedef Sim * TabSim;

/*Prototypes*/
TabSim TabSim_create(int size);
void TabSim_destroy(TabSim t);
Bool TabSim_insert(TabSim t, str key, void * value);
void * TabSim_query(TabSim t, str key);
Bool TabSim_remove(TabSim t, str key);
