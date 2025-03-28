#ifndef _ANIMALS_H_
#define _ANIMALS_H

#include "animal.h"

struct animal animals[] = {
	{ "human", 2 },
	{ "frog", 4 },
	{ "snail", 1 },
	{ "snake", 0 },
	{ "dog", 4 },
	{ "spider", 8 },
	{ "ant", 6 },
	{ "centipede", 100 }
};
#else
/* because this file contains definition of array we want to be extra careful */
#error "multiple includes of animal definitions !"
#endif /* _ANIMALS_H_ */
