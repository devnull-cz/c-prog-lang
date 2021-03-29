_Bool
isempty(char s[])
{
	return (s[0] == '\0');
}

int
main(void)
{
	return (isempty(""));
}
