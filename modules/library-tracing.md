## Library call tracing

- `ltrace` is the most widely used tool to print calls to library functions
  - it can provide indentation (`-n`)
  - can be used to do simple profiling (with `-tt`)
- to print calls within the program itself use `-e @MAIN`
  - in a different tool, `truss` (Solaris, \*BSD), one can do that with `-u
    a.out`

#source recurs.c
  - run with: `ltrace -n4 -tt ./a.out 5`

Note: `ltrace` can trace system calls as well with the `-S` option

Links:
  - http://techblog.rosedu.org/ltrace.html
  - https://blog.packagecloud.io/eng/2016/03/14/how-does-ltrace-work/
