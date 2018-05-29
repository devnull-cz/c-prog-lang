int
main(void)
{
	int a;	// not initialized

	a = a++;	// sequence point violation

	return (a);
}
