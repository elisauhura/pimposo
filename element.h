/* Element.h - By Vitor Silva */

#include "std.h"
#include "list.h"

typedef struct {
	str Name;
	str Articles[4]; /*dd, di, id, ii: eg: o, do, um , dum*/
	str LongDesc;
	str ShortDesc;
	List * ObjList;
	List * Attributes;
	List * Actions;
	str Animation;

	/*OOP*/
	void * __Super;
	void * __Child;
	void * __Self;
	str __Class;
	void (* free) (void * t);
} Element;

typedef struct {
	void * To; /*Place*/
	Bool Closed;

	/*OOP*/
	void * __Super; /*Element*/
	void * __Child;
	void * __Self;
	str __Class;
	void (* free) (void * t);
} Path;

typedef struct {
	void * Exit;
	
	/*OOP*/
	void * __Super; /*Element*/
	void * __Child;
	void * __Self;
	str __Class;
	void (* free) (void * t);
} Place;

typedef struct {
	str * Adjectives;
	Bool Hidden;

	/*OOP*/
	void * __Super; /*Element*/
	void * __Child;
	void * __Self;
	str __Class;
	void (* free) (void * t);
} Object;

/* @Actions
 - lookup -> return object description
 - catch -> send object from the place to the player
 - throw -> send object from the player to the place
 ...
*/

Element * Element_new(str name, str dd, str di, str id, str ii, str longdesc, str shortdesc, List * objlist, List * attributes, List * actions, str animation);
void Element_free(Element * e);