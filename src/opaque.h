/*
 * This is public header file, to be distributed with the library built
 * from opaque.c
 */

struct opaque;

typedef struct opaque *opaque_t;

void doStuff(struct opaque *f);
struct opaque *getOpaque(void);
