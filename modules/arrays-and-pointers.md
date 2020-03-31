# Arrays and pointers

In C, there is a strong relationship between arrays and pointers.

By definition, the value of a variable or an expression of type array is the
address of an element zero of the array.

```
pa = &a[0];     // [] is of higher precedence than &
pa = a;         // this gets the same result as above
```

heavy\_exclamation\_mark: Incrementing a pointer increments the value **by the
size of the object the pointer points to**.  Ie.

```
int a[] = { 0, 1, 2 };
int *p = a;

printf("%d\n", *(p + 2));       // will print 2
```

[ptr-inc.c](/src/ptr-inc.c)
