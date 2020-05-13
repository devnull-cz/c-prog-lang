# Non-transparent handles may cause issues

If your library is statelful, the state is often managed by a handle
used as an argument in the library function calls.  Let's say internally in the
library we need to track some ID and a position.  Those members are expected to
be used only by the library itself so the consumers of the library should use
the handle in a transparent way.   That is, they should not care nor use
whatever is inside the handle.

```C
/* mylib.h */
struct ml_hndl {
	int ml_id;
	int ml_pos;
};

/* mylib.c */
struct handle *
ml_init(void)
{
	/* allocate and init the handle first */
	/* ... */

	return (h);
}

/* mylib.c continues */
enum ml_err
ml_parse(struct handle *h, char *url)
{
	enum ml_err e = ML_OK;

	/* parse the URI */
	/* ... */

	return (e);
}

/* ... */
```

And the consumer would use it as follows:

```C
#include <mylib.h>

int
main(void)
{
	ml_err ret;
	struct ml_hndl *h;

	h = ml_init(void);
	if ((ret = ml_parse(h, "some URI")) != ML_OK)
		errx(1, "...");

	/* ... */
}
```

So far, so good.  However, what if the consumer code delves into the handle and
uses the information in there (because the header file is part of the library
and available to the consumer)?

```C
int
main(void)
{
	/* ... */

	print_debug("[Debug] handle ID: %d\n", h->md_id);

	/* ... */
}
```

This will work fine until the library provider changes the handle (believed to
be internal to the library):

```C
/* mylib.h */
struct ml_hndl {
	long long ml_id;	/* used to be an int */
	int ml_pos;
};
```

Unless the consumer code is recompiled after the change, which may not happen as
it could be some 3rd party software bought by the customer years ago, the debug
print is now incorrect as it only prints the first 4 bytes of the structure, not
8.

There are ways to mitigate that:

- use something non-revealing as a handle, like in index to the internal array
  of structures that keep the states.  That is possible but you now need to
  manage the internal structure that keeps the state structures.  You also
  cannot change the index type unless you recompile all the consumers as well.
- the library provider could use something called *incomplete types* and use
  them to provide an opaque (transparent) handle.
