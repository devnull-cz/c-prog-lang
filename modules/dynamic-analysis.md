## Dynamic analysis

- run-time analysis performed by running the program in an emulation layer
  (virtual machine), intercepting calls to memory allocator etc.
- can provide more detailed detection at the cost of performance and coverage -
  can detect only in the code paths actually executed (compared to static
  analysis)
  - the performance degradation incurred by dynamic analysis is usually
    much higher than the one of syscall/library tracing

:wrench: Task: Take a look at the code and try to find as many bugs as possible:
#source shell.c

Then compile the program with as many checks as possible and run the
program through the static analysis.

Then run it through Valgrind, perform couple of operations and exit the
program, i.e.

1. `valgrind ./a.out`
1. echo couple of "commands"
1. hit Ctrl-C

Also run it automatically, e.g.:

```
$ cat << EOF >/tmp/input
foo
bar
foo bar
EOF
$ valgrind ./a.out < /tmp/input
```

- try to compile the program with debug info (`-g`) and re-run valgrind with
  `--leak-check=full` and see the difference in the output.
- fix the program and re-run the test(s) again
