## :wrench: `tr` variants

Implement functionality provided by the following command with the specific
options.  Just hardcode the parameter in the code, e.g.

```C
#define CHAR_DO_DEL     'x'
```

See the tr(1) manual page if unsure.

## Variant 1: delete a single char (`tr -d '<char>'`)

Example:
```
$ cat /etc/passwd | tr -d r > output
$ cat /etc/passwd | ./a.out > output2
$ diff output output2
$ echo $?
0
```

## Variant 2: squeeze a single char (`tr -s '<char>'`)

Squeeze multiple occurrences of the character into one.

```
$ echo "hellooooooo, wooooooorld" | tr -s o
hello, world
```

Now for both variants, you can extend it to use not a single character,
but a character set (using character arrays), just like `tr` does.
