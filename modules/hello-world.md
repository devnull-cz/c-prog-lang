# First C program: "Hello, world"

- :eyes: [hello-world1.c](/src/hello-world1.c), will compile with warnings
- use `gcc hello-world1.c` to compile it, `./a.out` to run it
	- or `gcc -o hello-world1 hello-world1.c` if you want a specific output
- we recommend vim(1) to edit your files (use ":syntax on" for syntax
  highlighting if not the default settings)
	- see http://mff.devnull.cz/vim-tips.html
- C runtime system is very small, printf is not part of it, that's why you need
  an include file to provide the function prototype (ie. the return type and its
  parameters)
- fixed code with no warnings: hello-world2.c
