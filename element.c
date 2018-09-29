/* Element.c - By Vitor Silva*/

#include "element.h"

#include <stdlib.h>

Element * newElement(str name) {
    Element * e = malloc(sizeof(Element));
    if(e == NULL) return NULL;
    int i;
    for(i = 0; name[i] != '\0'; i++);
	e->Name = malloc(sizeof(char) * (i + 1));
	if(e->Name == NULL) {
		free(e);
		return NULL;
	}
	for(i = 0; name[i] != '\0'; i++) e->Name[i] = name[i]; e->Name[i] = '\0';

    char class[] = "Element";
	e->__Class = malloc(sizeof(char) * 8);
	if(e->Name == NULL) {
        free(e->Name);
		free(e);
		return NULL;
	}
	for(i = 0; class[i] != '\0'; i++) e->__Class[i] = class[i]; e->__Class[i] = '\0';
    return e;
}

void freeElement(Element * e) {
    if(e == NULL) return;
    free(e->Name);
    free(e->__Class);
    free(e);
}