# Common mistakes - defines

Some of you often end up doing the following:
```C
#define MYDEF = 3
```

And you hit a syntax error when `MYDEF` is used later in the code.

What happens?  A preprocessor replaces occurences of `MYDEF` with whatever is
after `MYDEF`, and separated from it with a sequence of white spaces (tabs,
spaces, newlines if escaped).

In the case above, `MYDEF` will be literary replaced with "= 3".

Check with `gcc -E` (or `cpp`) which stops after the preprocessor phase (ie. it
does NOT compile anything).  The following is in :eyes:
#source common-mistake-with-define.c

```C
#define MYDEF = 3

if (i < MYDEF) {
	// ...
}
```

The code above will end up in a syntax error as `i < = 3` is not a correct
expression in C (because of the space between `<` and `=`).

```
$ gcc -E common-mistake-with-define.c
...
...

if (i < = 3) {

}
```

See the
#module modules/preprocessor.md preprocessor
for more information.
