/* Std.c - By Vitor Silva */
#include <stdlib.h>

#include "std.h"

Object * Object_new(void (* new) (Object * obj)) {
    Object * obj = malloc(sizeof(Object));
    new(obj);
    return obj;
}

/*Add implementation*/
ObjectPack * Object_pack(int n, ...);
void * Object_call(Object * obj, Str method, ObjectPack * pack);

void Object_free(Object * obj) {
    obj->free(obj);
}

Str Str_copy(Str string) {
    int i;
    /*Discover string size*/
    for(i = 0; string[i] != '\0'; i++);
    i++; /*for the \0 character*/
    Str q = malloc(sizeof(char)*i);
    if(q == NULL) goto ret;
    for(int j = 0; j < i; j++) q[j] = string[j];
    ret:
        return q;
}