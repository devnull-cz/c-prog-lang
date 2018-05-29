#include <stdio.h>
#include <stdlib.h>

void
bytecnt2str(uint64_t num)
{
	int idx = 0;
	uint64_t rest;

	while (num >= 1024) {
		rest = num % 1024;
		num /= 1024;
		idx++;
	}
                                                                                
  	// access string literal as array
	char u = " KMGTPE"[idx];

	// printf("%llu\n", rest);

	printf("%llu%s %ciB\n", num, rest > 0 ? "+" : "", u);
#if 0
	if (rest < 1000)
		printf(".%llu", rest / 100);
	else
		printf(".9");
#endif
}

int
main(int argc, char *argv[])
{
	bytecnt2str(atoi(argv[1]));

	return (0);
}
