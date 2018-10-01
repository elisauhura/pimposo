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
    TabSim_insert(hash, rock->Name, rock);
    TabSim_insert(hash, paper->Name, paper);
    puts("Look for the paper element");
    if(paper == TabSim_query(hash, "Paper"))
        puts("Found");
    puts("Create a list with the three elements");
    List l = List_create();
    l = List_insert(l, rock, rock->Name);
    l = List_insert(l, paper, paper->Name);
    l = List_insert(l, scissor, scissor->Name);
    puts("Look for the rock element");
    if(rock = List_query(l, "Rock"))
        puts("Found");
    puts("Remove the rock element");
    List_Pack t = List_remove(l, "Rock");
    l = t.l;
    if(List_query(l, "Rock") == NULL)
        puts("Removed");
    puts("Destroy data structures");
    freeElement(rock);
    freeElement(paper);
    freeElement(scissor);
    TabSim_destroy(hash);
    puts("Sucess");
    return 0;
}
