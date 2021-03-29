#include <stdio.h>

union bar_u {
	unsigned short i; // 2 bytes
	struct {
		unsigned char low;
		unsigned char high;
	} bytes;
};

int
main(void)
{
	union bar_u bar = { .i = 256 };

	printf("size = %zu bytes\n", sizeof (bar));
	printf("low: %x high: %x\n", bar.bytes.low, bar.bytes.high);

	if (bar.bytes.low == 1)
		printf("big endian\n");
	else
		printf("little endian\n");
}
