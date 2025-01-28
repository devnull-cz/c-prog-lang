#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct item {
	int header;
	size_t len;
	char payload[]; // must be last member
};

static struct item *
allocate(size_t payload_len)
{
	/*
	 * offsetof(struct item, payload) might be better to use here as
	 * otherwise we might allocate more than necessary due to padding that
	 * could otherwise be used for the flexible array member.
	 */
	struct item *p = malloc(sizeof (struct item) +
	    payload_len * sizeof (p->payload[0]));
	if (p == NULL)
		return (p);

	p->len = payload_len;

	for (size_t i = 0; i < p->len; i++)
		p->payload[i] = 'A' + i;

	return (p);
}

int
main(void)
{
	struct item *p = allocate(30);

	/*
	 * This is always the size without the flexible array member.  Note that
	 * padding might be inserted by the compiler.
	 */
	printf("sizeof (item): %zu\n", sizeof (*p));
	printf("offsetof (item, payload): %zu\n",
	    offsetof(struct item, payload));

	for (size_t i = 0; i < p->len; ++i) {
		printf("%zu: %c\n", i, p->payload[i]);
	}

	free(p);
}
