/*
 * Implement function copy_s2a().  Do not modify the main() code.  When you
 * build the resulting code with "gcc -Wall -Wextra", it must print no warnings
 * at all.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>

#if 0
copy_s2a()
{
}
#endif

int
main(void)
{
        char a[1024];
        char *s = "hello, world";
        char *s2 = \
	    "I watched C-beams glitter in the dark near the Tannhauser Gate.";

        assert(strlen (s) < sizeof (a));
        assert(strlen (s2) < sizeof (a));

	/* Must print 13 */
        printf("Chars copied: %zu\n", copy_s2a(a, s));
        /* This must print "hello, world" */
        printf("%s\n", a);

	/* Must print 63. */
        printf("s2 len: %zu\n", strlen(s2));
	/* Must print 64 as the terminating '\0' was also copied. */
        printf("Chars copied: %zu\n", copy_s2a(a, s2));
        /* This must print the full quote. */
        printf("%s\n", a);
}
