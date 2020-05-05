## Debugger

- can be used for both live debugging and post-mortem analysis (from core file
  produced by the program)
  - works by inserting breakpoints and displaying memory of the process
    - this is usually done using the ptrace(2) syscall
- most common debuggers: gdb, lldb, dbx, mdb
  - some of them have the concept of plug-ins

- compiling for debugging: the `-g` compiler option adds debugging information
  to the resulting binary, in particular mapping of assembly instructions to
  source code lines
  - one can debug without this data, just some assembly knowledge is required

- will describe gdb here

- compile and run the program from gdb:
```
  cc -Wall -g random.c
  gdb ./a.out
  > r
```
- exiting the debugger:
```
  > quit
```
    - or Ctrl-D

- to get the core file, the system limit for core file may need to be bumped
```
  ulimit -c 1000000
```

  - and re-run the program again

- display the stack trace at the moment of breakpoint stop/crash:

```
  > backtrace
```

- see where exactly it crashed:

```
  > disassembly
  > info reg
  > list
```

- insert breakpoint

```
  > b main
  > b run
```

  - can also insert breakpoint to particular line (if the program was compiled
    with line information):

```
  > b 8
```

  - print breakpoints:

```
    > info breakpoints
```

- stepping
  - single line (assembly instruction) stepping:

```
    > next
```

  - step through:

```
    > step
```

- printing memory

  - print variable value:

```
    > print idx
    > print p
```

  - can use the usual dereference/ref operators:
    (once inside run())

```
    > print *p[idx]
```

- print a variable in each step:

```
  > display i
```

  - to disable the printing:

```
    > delete display i
```

- breakpoints can be conditional:

```
  > break 14 if i == idx
```
