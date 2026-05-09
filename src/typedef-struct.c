typedef struct mystruct_s {
        int a;
        char c;
} mystruct_t;

int
main(void)
{
	struct mystruct_s s;
	struct mystruct_s *p = &s;
	mystruct_t *p2;

	/* No error or warning.  The pointers are of the same type. */
	p2 = p;
}
