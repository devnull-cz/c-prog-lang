#include <stdio.h>

#include "animals.h"
#include "animal_maxlegs.h"

int
main(void)
{
	printf("%s\n",
	    maxlegs(animals, sizeof (animals) / sizeof (animals[0]))->name);
}
