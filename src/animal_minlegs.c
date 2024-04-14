#include <stddef.h>

#include "animal.h"

/*
 * Technically, this file does not have to include the header file which
 * contains the prototype of the function defined here, however it is a
 * good practice, because in case the function signature changes only here
 * and not in the header file, the (modern) compiler will fail the compilation
 * of this file.
 */
#include "animal_minlegs.h"

size_t
count_minlegs(struct animal *animals, size_t len, size_t min)
{
	size_t count = 0;

	for (size_t i = 0; i < len; i++) {
		if ((animals + i)->legs >= min)
			count++;
	}

	return (count);
}


