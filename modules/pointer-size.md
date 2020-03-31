# Pointer size

```
int *p;
```

`sizeof (p)` is an **address size**, in our case either 32 or 64 bits depending
on how your code was compiled.

```C
#include <stdio.h>

int
main(void)
{
	int *p;
	printf("%zu\n", sizeof (p));
}
```

```
$ cc main.c
$ file a.out
a.out: Mach-O 64-bit executable x86_64
$ ./a.out
8
```

The `sizeof (*p)` is equivalent to `sizeof (int)` (as that is what the type of
`*p` is).
