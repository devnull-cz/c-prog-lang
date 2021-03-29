#include <stdio.h>

int
main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] != '-')
			printf("%p %s\n", argv[i], argv[i]);
	}
}
