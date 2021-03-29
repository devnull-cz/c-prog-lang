#include <stdio.h>
#include <stdint.h>

int
main(void)
{
	uintptr_t uptr;
	char *ptr = "foo";

	uptr = (uintptr_t)ptr;

	printf("%p\n", ptr);
	printf("0x%lx\n", uptr);
}
