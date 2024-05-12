/*
 * This is public header file, to be distributed with the library built
 * from foo.c
 */

struct foo;

typedef struct foo *foo_t;

void doStuff(struct foo *f);
struct foo *getFoo(void);
