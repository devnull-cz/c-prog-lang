#include <stdlib.h>
#include <stdio.h>

struct item {
	int header;
	int len;
	char payload[]; // must be last member
};

static struct item *
allocate(size_t payload_len)
{
	// offsetof(struct item, payload) might be better to use here.
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

	for (int i = 0; i < p->len; ++i)
		printf("%d: %c\n", i, p->payload[i]);

	free(p);

	return (0);
}
