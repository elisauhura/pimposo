#include "element.h"

#include "stdio.h"

int main(void) {
	Element * e = newElement("Pimp");
	puts(e->Name);
	freeElement(e);

	puts("Test Complete");
	return 0;
}
