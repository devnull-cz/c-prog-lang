#include <stdio.h>

int
main(void)
{
	printf("Dec\tOct\tChar\n");
	for (int i = 'a'; i <= 'z'; ++i)
		printf("%d\t%o\t%c\n", i, i, i);
}
