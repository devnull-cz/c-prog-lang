/*
 * Naive implementation of strcmp().
 * Compile with -DTEST to see the behavior of strcmp() in libc.
 */

#ifdef TEST
#include <stdio.h>
#include <string.h>	// for testing
#else
#define	mystrcmp strcmp
#endif

#include <assert.h>

static int
mystrcmp(const char *s1, const char *s2)
{
	int ret = 0;

	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 > *s2)
			return 1;
		else if (*s1 < *s2)
			return -1;

		s1++;
		s2++;
	}

	if (*s1 != '\0')
		return 1;
	else if (*s2 != '\0')
		return -1;

	return ret;
}

int
main(void)
{
	assert(strcmp("", "") == 0);
	assert(strcmp("", "foo") < 0);
	assert(strcmp("foo", "") > 0);
	assert(strcmp("abc", "abd") < 0);
	assert(strcmp("foo", "bar") > 0);
	assert(strcmp("foo", "foo") == 0);
	assert(strcmp("foo", "fooz") < 0);
	assert(strcmp("fooz", "foo") > 0);
}
