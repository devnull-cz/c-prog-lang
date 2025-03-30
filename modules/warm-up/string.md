## Create a special string

- :wrench: write code to print the output further below using a single `printf`
  with a single conversion specification like this:

```
printf("%s\n", str);
```

- Your code must not have `x` in it.  The only string literal allowed in your
  code must be `"%s\n"` in `printf`.  If you use `grep` on your code, its output
  must be empty as follows:

```
$ grep x main.c
$
$ grep '".*"' main.c | grep -v 'printf.*%s'
$
```

When you compile your code, the expected output follows (`<tab>` means a literal
tabelator character):

```
hello
world
<tab>x
'
```

#solution create-string.c
