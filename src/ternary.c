#include <stdio.h>

#define	PrintInt(expr)	printf("%s : %d\n", #expr, (expr))

int
max(int x, int y)
{
	(x > y) ? return x : return y;
}

int main()
{
	int a = 10, b = 20;

	PrintInt(a);
	PrintInt(b);
	PrintInt(max(a,b));
}
