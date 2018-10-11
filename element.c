/* Element.c - By Vitor Silva*/

#include "std.h"
#include "element.h"

#include <stdlib.h>

Element * Element_new(Str name, Str dd, Str di, Str id, Str ii, Str longdesc, Str shortdesc, List * objlist, List * attributes, List * actions, Str animation) {
    Element * e = malloc(sizeof(Element));
    if(e == NULL) return NULL;
	e->Name = Str_copy(name);
	e->Articles[0] = Str_copy(dd);
	e->Articles[1] = Str_copy(di);
	e->Articles[2] = Str_copy(id);
	e->Articles[3] = Str_copy(ii);
	e->LongDesc = Str_copy(longdesc);
	e->ShortDesc = Str_copy(shortdesc);
	e->ObjList = objlist;
	e->Attributes = attributes;
	e->Actions = actions;
	e->Animation = Str_copy(animation);


	e->__Super = NULL;
	e->__Child = NULL;
	e->__Self = e;
	e->__Class = Str_copy("Element");
    return e;
}

void freeElement(Element * e) {
    if(e == NULL) return;
    free(e->Name);
	free(e->Articles[0]);
	free(e->Articles[1]);
	free(e->Articles[2]);
	free(e->Articles[3]);
	free(e->LongDesc);
	free(e->ShortDesc);
	free(e->Animation);
	List_free(e->ObjList);
	List_free(e->Attributes);
	List_free(e->Actions);
    free(e->__Class);
    free(e);
}