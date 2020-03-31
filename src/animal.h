#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <stddef.h>	// for size_t
#include <limits.h>

#ifndef NAME_MAX
#define	NAME_MAX	PATH_MAX
#endif

struct animal {
	char name[NAME_MAX]; // filename should be sufficient even
                                // for these long Latin names
	size_t legs;		// can have many legs
};

#endif /* _ANIMAL_H_ */
