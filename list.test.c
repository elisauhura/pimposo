/* list.test.c - by Vitor Silva */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    puts("Testing List");
    int i[4] = {1,2,3,4};
    puts("Creating List");
    List l = List_create();
    puts("Adding elements");
    l = List_insert(l, i + 0, "um");
    l = List_insert(l, i + 1, "dois");
    l = List_insert(l, i + 2, "tres");
    l = List_insert(l, i + 3, "quatro");
    puts("Quering some elements (3 and 1)");
    int * q = List_query(l, "tres");
    int * p = List_query(l, "um");
    printf("%d\n", * q);
    printf("%d\n", * p);
    puts("Removing 1");
    List_Pack pack = List_remove(l, "um");
    l = pack.l;
    puts("Checking if 1 was removed");
    if(List_query(l, "um") == NULL)
        puts("Success");
    puts("Freeing it");
    List_destroy(l);

    puts("Test Complete");
    return 0;
}
