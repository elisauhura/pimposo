/* Element.h - By Vitor Silva */

#include "type.h"

typedef struct {
	str Name;
	str Articles[4];
	str LongDesc;
	str ShortDesc;
	Element ObjList[];
	void * Attributes;
	str Action[];
	str Animation;

	/*OOP*/
	void * __Super;
	void * __Child;
	void * __Self;
	str __Class;
} Element;

typedef struct {
	void * To; /*Place*/
	Bool Closed;

	/*OOP*/
	void * __Super; /*Element*/
	void * __Child;
	void * __Self;
	str __Class;
} Path;

typedef struct {
	void Exit[];
	
	/*OOP*/
	void * __Super; /*Element*/
	void * __Child;
	void * __Self;
	str __Class;
} Place;

typedef struct {
	str Adjectives[];
	Bool Hidden;

	/*OOP*/
	void * __Super; /*Element*/
	void * __Child;
	void * __Self;
	str __Class;
} Object;

/* @Actions
 - lookup -> return object description
 - catch -> send object from the place to the player
 - throw -> send object from the player to the place
 ...
*/
