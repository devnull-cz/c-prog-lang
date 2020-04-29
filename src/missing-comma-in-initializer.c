/*
 * An example why always keeping a comma after the last initializer might be a
 * good idea.
 *
 * See https://en.wikipedia.org/wiki/Tears_in_rain_monologue for more info.
 */
#include <stdio.h>

char *s[] = {
	"All",
	"those",
	"moments",
	"will",
	"be",
	"lost",
	"in",
	"time,",
	"like",
	"tears"		// no comma after the last initializer
/*
 * Now imagine adding two new strings and forgetting to add a comma after the
 * previously last initializer.  So, change 0 to 1, compiler, and run.  What
 * happened?
 */
#if 1
	"in",
	"rain.",
#endif
};

int
main(void)
{
	for (int i = 0; i < sizeof (s) / sizeof (char *); ++i)
		printf("%s\n", s[i]);
}
