/*
 * Build with:
 *
 *	gcc -std=c99 request-c99.c
 *
 * and also without it.
 */
#if __STDC_VERSION__ != 199901L
#error "C99 (and not greater) compiler required."
#endif

int
main(void)
{
}
