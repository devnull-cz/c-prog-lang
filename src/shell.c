#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <err.h>

#define BUFSIZE 1024

char
*shReadLine(void)
{
	int bufsize = BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer) {
		err(1, "Error allocating buffer");
	}

	while (1) {
		c = getchar();

		if (c == '\n' || c == EOF) {
			buffer[position] = '\0';
			return buffer;
		} else {
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize) {
			bufsize += BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer) {
				err(1, "Error allocating buffer");
			}
		}
	}
}

char
**shParseLine(char *line)
{
	char **args = malloc(BUFSIZE * sizeof(char*));
	size_t i = 0;
	int pos = 0;

	while(i < strlen(line)) {
		char *tmp = malloc(BUFSIZE * sizeof(char*));
		int k = 0;
		if (line[i] == '"') {
			i++;
			while(line[i] != '"' && i < strlen(line)) {
				tmp[k] = line[i];
				i++;
				k++;
			}
		} else {
			while(!isspace(line[i]) && i < strlen(line)) {
				tmp[k] = line[i];
				i++;
				k++;
			}
		}
		while(isspace(line[i]) && i < strlen(line))
			i++;
		args[pos] = tmp;
		pos++;

	}
	args[pos] = NULL;
	return (args);
}


void
shStart(void)
{
	char *line;
	char **args;
	int status = 1;
	char *cwd = (char*)malloc(BUFSIZE * sizeof(char*));
	char *usr = (char*)malloc(BUFSIZE * sizeof(char*));
	char *hm = (char*)malloc(BUFSIZE * sizeof(char*));

	do {
		cwd = getcwd(cwd, BUFSIZE);
		usr = getenv("USER");
		hm = getenv("HOME");
		cwd += strlen(hm) - 1;
		cwd[0] = '~';
		printf("%s@%s> ", usr, cwd);

		line = shReadLine();
		args = shParseLine(line);
		// Do something with args.

		free(line);
		free(args);
	} while (status);
}

int
main(void)
{
	shStart();
}
