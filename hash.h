/* Hash.h - by Vitor Silva & Lucas Sobrinho */

#include "type.h"
#include "element.h"
#include "list.h"

typedef struct {
	str key;
	void * value;
} Sim;

typedef struct{
	int size;
	List * entries;
} TabSim;

/*Prototypes*/
TabSim * TabSim_create(int size);
void TabSim_destroy(TabSim * t);
Bool TabSim_insert(TabSim * t, str key, void * value);
Element * TabSim_query(TabSim * t, str key);
Bool TabSim_remove(TabSim * t, str key);
