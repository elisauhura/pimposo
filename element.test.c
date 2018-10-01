#include "element.h"

#include "stdio.h"

int main(void) {
	puts("Testing Element");

	puts("Creating Element");
	Element * e = newElement("Pimp");

	puts("Getting its name (Pimp)");
	puts(e->Name);

	puts("Freeing it");
	freeElement(e);

	puts("Test Complete");
	return 0;
}
