/* Test All Modules - by Vitor Silva*/

#include "element.h"
#include "hash.h"
#include "list.h"

#include <stdio.h>

int main() {
    puts("Create 3 elements: Rock, Paper, Scissor");
    Element * rock = newElement("Rock");
    Element * paper = newElement("Paper");
    Element * scissor = newElement("Scissor");
    puts("Add rock and paper to a hash table size 2");
    TabSim hash = TabSim_create(2);
    TabSim_insert(hash, rock->Name, )
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    return 0;
}
