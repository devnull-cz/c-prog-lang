# Reading complex declarations

To read a complex declaration, you use
#module operator-precedence.md operator priorities
and watch for parentheses.

```C
char **argv
```

`argv` is a pointer to a pointer to `char`

```C
int (*a)[10]
```

`a` is a pointer to an array of 10 `int`s

```C
int *a[10]
```

`a` is an array of 10 pointers to `int`

```C
void *myfunc()
```

`myfunc` is a function returning a pointer to `void`

```C
void (*myfunc)()
```

`myfunc` is a pointer to a function returning `void`

```C
char (*(*x())[])()
```

`x` is a function returning pointer to an array of pointers to a function
returning a `char`

```C
char (*(*x[3])())[5]
```

`x` is an array of 3 pointers to a function returning a pointer to an
array of 5 `char`s

## How to read it

1. find the identifier (non keyword or custom type) of a variable or function
2. start decoding:
        - left to right
        - `)`  => reverse decoding direction
        - `()` => denotes function
        - `[]` => array
        - `;`  => reverse the direction
        - when reading from right to left, we can hit:
        - `(`   => reverse the direction
        - `*`   => pointer
        - type identifier => starts the whole definition

Example:
```C
char *(*(**foo[][8])())[];
```

You can mentally simplify as:

```C
char *(*SOME_FUNCTION)[];
```

Where `SOME_FUNCTION` is `(**foo[][8])()`

Read as:

`foo` is an array of arrays of 8 pointers to a pointer to a function
returning a pointer to an array of pointers to a `char`.

Alternatively, you can do it via two simpler steps:

```C
typedef char *a_of_p[];
typedef a_of_p *(**foo[][8])();
```

#source complex-declaration.c

:wrench: Practice:

```C
int *(*(*fp1)(int))[10];
char (*(*x())[])()
double *f()[]           // this is not legal in C as a function cannot
                        // return an array
```
