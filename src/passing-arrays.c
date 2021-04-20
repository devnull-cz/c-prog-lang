void
myfn(int a[2][2])
{
        return;
}

int
main(void)
{
	/*
	 * You need () as "*p[2]" would be "p is an array of pointers to int" as
	 * [] has higher priority.  More on that later.
	 */
        int (*p)[2];
        int (*p2)[3];

        myfn(p);	// OK
        myfn(p2);	// will trigger a warning
}
