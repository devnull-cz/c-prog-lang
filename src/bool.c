#include <stdio.h>

#if 0
/*
 * Include the following header if you are certain your (possibly legacy)
 * application never used "bool", "true", nor "false" on its own.
 *
 * Standard defined macro __bool_true_false_are_defined will expand to 1 if
 * those three macros are defined.
 */
#include <stdbool.h>
#endif

int
main(void)
{
#if __bool_true_false_are_defined
	bool flag = false;
#else
	_Bool flag = 0;
#endif

	printf("%d\n", flag);
#if __bool_true_false_are_defined
	flag = true;
#else
	flag = 1;
#endif
	printf("%d\n", flag);
}
