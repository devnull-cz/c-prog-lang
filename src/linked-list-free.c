#include <stdio.h>
#include <stdlib.h>
#include <err.h>

struct item {
	int value;
	struct item *next;
};

struct item *head;

int
main(int argc, char *argv[])
{
	if (argc != 2)
		errx(1, "usage: %s <num>", *argv);

	for (int i = 0; i < atoi(argv[1]); i++) {
		struct item *p = (struct item *)malloc(sizeof (struct item));
		if (p == NULL)
			err(1, "malloc");
		p->value = i;
		p->next = head;
		head = p;
	}

	for (struct item *p = head; p != NULL; p = p->next) {
		printf("%d\n", p->value);
	}
}
