void
myfn(int a[2][2])
{
        return;
}

int
main(void)
{
        int (*p)[2];
        int (*p2)[3];

        myfn(p);	// OK
        myfn(p2);	// will trigger a warning
}
