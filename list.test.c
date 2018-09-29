/* list.test.c - by Vitor Silva */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    int i[4] = {1,2,3,4};
    List l = List_create();
    l = List_insert(l, i + 0, "um");
    l = List_insert(l, i + 1, "dois");
    l = List_insert(l, i + 2, "tres");
    l = List_insert(l, i + 3, "quatro");
    int * q = List_query(l, "tres");
    int * p = List_query(l, "um");
    printf("%d\n", * q);
    printf("%d\n", * p);
    List_Pack pack = List_remove(l, "um");
    l = pack.l;
    if(List_query(l, "um") == NULL)
        puts("Success");
    List_destroy(l);
    return 0;
}
