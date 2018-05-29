#include <stdlib.h>

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
		p->payload[i] = 'A';

	return (p);
}

int
main(void)
{
	struct item *p = allocate(100);

	// do sth to make sure the code is not optimized away

	return (0);
}
