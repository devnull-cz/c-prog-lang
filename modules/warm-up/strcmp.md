## :wrench: Implement `strcmp`

Implement:

```C
int strcmp(const char *s1, const char *s2);
```

Returns (according to the strcmp(3) manual page):

> an integer greater than, equal to, or less than 0, according as the
string s1 is greater than, equal to, or less than the string s2.

You can add the following piece of code into your `main` function to test it
(and include `assert.h`):

```C
assert(strcmp("", "") == 0);
assert(strcmp("", "foo") < 0);
assert(strcmp("foo", "") > 0);
assert(strcmp("abc", "abd") < 0);
assert(strcmp("foo", "bar") > 0);
assert(strcmp("foo", "foo") == 0);
assert(strcmp("foo", "fooz") < 0);
assert(strcmp("fooz", "foo") > 0);
```

If any assert triggers, your implementation is buggy.

#solution strcmp.c

:wrench: Compare your solution with the above. Try to reimplement
it so that it is as smallest (in terms of
[Lines Of Code](https://en.wikipedia.org/wiki/Source_lines_of_code))
as possible.
