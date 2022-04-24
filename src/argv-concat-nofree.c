/*
 * Like argv-concat.c but do it in a loop, creating a memory leak.
 *
 * Run a performance monitor then to see how the memory use of the running
 * program increases quickly.  On Linux, macOS, etc., just run:
 *
 *	top -s 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	size_t len = 0;

	while (1) {
		fprintf(stderr, "%c", '.');

		for (int i = 1; i < argc; i++)
			len += strlen(argv[i]);

		char *str = malloc(len + 1);
		if (str == NULL)
			err(1, "malloc");

		for (int i = 1; i < argc; i++) {
			for (size_t j = 0; j < strlen(argv[i]); j++) {
				printf("%c\n", argv[i][j]);
				*str++ = argv[i][j];
			}
		}
		*str = '\0';
	}
}
