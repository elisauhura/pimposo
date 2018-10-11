/* Std.c - By Vitor Silva */

#ifndef STD_VSS
#define STD_VSS

typedef char * Str;
typedef short int Bool;

typedef struct {
    void * __Super;
    void * __Child;
    void * __Self;
    void * __Ext;
    Str __Class;
    void (* free) (void * t);
} Object;

typedef struct ObjectPack{
    Object * value;
    struct ObjectPack * next;
} ObjectPack;

Object * Object_new(void (* new) (Object * obj));
ObjectPack * Object_pack(int n, ...);
void * Object_call(Object * obj, Str method, ObjectPack * pack);
void Object_free(Object * obj);

Str Str_copy(Str string);

#endif