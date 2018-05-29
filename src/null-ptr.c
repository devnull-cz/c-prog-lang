#include <stdio.h>

int
main(void)
{
	int *p = NULL;

	printf("%p\n", p);  // This might print '(nil)' on some systems.
			    // Use newline to flush the buffer.
	*p = 1;
	printf("%d", *p);

	return (0);
}
