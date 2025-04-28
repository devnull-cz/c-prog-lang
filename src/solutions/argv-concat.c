#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	size_t len = 0;

	for (int i = 1; i < argc; i++)
		len += strlen(argv[i]);

	char *str = malloc(len + 1);
	if (str == NULL)
		err(1, "malloc");
	char *origstr = str;

#if STRNCAT
	for (int i = 1; i < argc; i++)
		strncat(str, argv[i], strlen(argv[i]));
#else
	for (int i = 1; i < argc; i++) {
		for (size_t j = 0; j < strlen(argv[i]); j++) {
			printf("%c\n", argv[i][j]);
			*str++ = argv[i][j];
		}
	}
	*str = '\0';
#endif

	printf("'%s'\n", origstr);
	free(origstr);
}
