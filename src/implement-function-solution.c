#include <assert.h>
#include <string.h>
#include <stdio.h>

/*
 * Implement function copy_s2a().
 */
size_t
copy_s2a(char *dst, char *src)
{
	size_t n = 0;

	while ((*dst++ = *src++) != '\0')
		++n;

	/* ++ for '\0' as that was not counted. */
	return (++n);
}

int
main(void)
{
        char a[1024];
        char *s = "hello, world";
        char *s2 = \
	    "I watched C-beams glitter in the dark near the Tannhauser Gate";

        assert(strlen (s) < sizeof (a));
        assert(strlen (s2) < sizeof (a));

        printf("Chars copied: %zu\n", copy_s2a(a, s));
        /* This must print "hello, world" */
        printf("%s\n", a);

	/* Must print 62. */
        printf("s2 len: %zu\n", strlen(s2));
	/* Must print 63 as the terminating '\0' was also copied. */
        printf("Chars copied: %zu\n", copy_s2a(a, s2));
        /* This must print the Blade Runner quote. */
        printf("%s\n", a);
}
