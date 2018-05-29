#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <stddef.h>	// for size_t
#include <limits.h>

struct animal {
	char name[NAME_MAX]; // filename should be sufficient even
                                // for these long Latin names
	size_t legs;		// can have many legs
};

#endif /* _ANIMAL_H_ */
