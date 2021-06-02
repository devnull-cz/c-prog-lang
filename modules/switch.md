# `switch` statement

```C
switch (expression) {
	case constant1:
		// statements
		break;
	case constant2:
		// statements
		break;
	.
	.
	.
	default:
		// default statements
}
```

Each `case` is a label.  For that reason, you must `break` unless you want to
code fall through.  The reason for that is historical and time showed it was not
the right decision.

Very often used for command line option processing.

```C
int opt;

while ((opt = getopt(argc, argv, "c:")) != -1) {
	switch (opt) {
	case 'c':
		/*
		 * optarg should be copied since it might be
		 * overwritten by another option or freed by getopt()
		 */
		if ((code = strdup(optarg)) == NULL)
			err(1, "cannot alloc memory for -c optarg");
		break;
	case '?':
		fprintf(stderr, "unknown option: '%c'\n", optopt);
		usage(argv0);
		break;
	}
}
```

#source switch.c
