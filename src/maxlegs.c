#include "animal_maxlegs.h"

static size_t
getlegs(struct animal *a)
{
	return (a->legs);
}

struct animal *
maxlegs(struct animal *a, size_t len)
{
	struct animal *p = a, *max = a;

	for (size_t i = 0; i < len; i++) {
		if (getlegs(p + i) >= getlegs(max))
			max = p + i;
	}

	return (max);
}
