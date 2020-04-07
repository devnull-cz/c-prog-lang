struct foo {
    int x;
    int y;
};

void
doStuff(struct foo *f)
{
	f->x = 1;
	f->y = 2;
}
