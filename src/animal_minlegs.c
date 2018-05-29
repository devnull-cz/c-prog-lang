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


