## Create a special string

- :wrench: write code to print the output further below using a single `printf`
  with a single conversion specification like this:

```
printf("%s\n", str);
```

- Your code must not have `x` in it.  The only string literal allowed in your
  code must be `"%s\n"` in `printf`.

```
$ grep x main.c
$
$ grep '".*"' main.c | grep -v 'printf.*%s'
$
```

Expected output follows (`<tab>` means a literal tabelator character):

```
hello
world
<tab>x
'
```

Solution:
#source create-string.c
