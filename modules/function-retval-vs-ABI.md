# Function return values and ABI

Let's look at the following code.  Obviously, the function does not return its
value while it definitely should have.  What happens if we use the function
return value anyway?

#source why-it-works.c

```C
#include <stdio.h>

int
addnum(int n1, int n2)
{
        int n = n1 + n2;
}

int
main(void)
{
        printf("%d\n", addnum(1, 99));
}
```

It simply cannot work, right?  **Oh, wait..., it does!?!**

```
$ cc why-it-works.c
$ ./a.out
100
```

**So what happened???**

Well, it does not really work.  It "works" by accident.  Let's look at it more
closely.  To establish a common environment, I will be using
the Linux lab at Malá Strana which you all have access to, so that you can try
and see.

Before I begin, let me give you more information:

- It depends on a system and its version, and a compiler and its version.
	- You can also try the `clang` compiler later on the same machine.
- Will be using `gcc` which defaults to generate 64 bit binaries on the Linux
  distro installed on u-pl3.ms.mff.cuni.cz (and other machines in the lab).
- 64 bit binaries on x86 use [X86-64 ABI](https://en.wikipedia.org/wiki/X86-64)
- [ABI](https://en.wikipedia.org/wiki/Application_binary_interface) is not
  [API](https://en.wikipedia.org/wiki/Application_programming_interface)
- By this ABI (it's law!), the first two function integer arguments are passed
  through the general purpose **edi** and **esi** registers
- Integer function return value is passed back to the caller via the general
  purpose **eax** register
- **The stack on x86 grows down**

Let's compile the code and disassemble it.  All we need are the `main` and
`addnum` function.  See my notes inline.

```
$ cc why-it-works.c
$ objdump -d a.out
...
<removed non-relevant stuff>
...
0000000000001145 <addnum>:
    1145:	55                   	push   %rbp
    1146:	48 89 e5             	mov    %rsp,%rbp

    	- initialize a frame pointer for this function.

    1149:	89 7d ec             	mov    %edi,-0x14(%rbp)
    114c:	89 75 e8             	mov    %esi,-0x18(%rbp)

	- here we put both function arguments on a stack.  As we already
	  learned, function arguments may be used within a function as local
	  variables, so they need to be on a stack.

	- why we put them to -0x14 and -0x18 offsets from the base?  That's just
	  what this gcc version does.  They are 4 bytes apart as we work with 4
	  byte integers.

    114f:	8b 55 ec             	mov    -0x14(%rbp),%edx
    1152:	8b 45 e8             	mov    -0x18(%rbp),%eax

	- moved the values of our local variables to general purpose registers

    1155:	01 d0                	add    %edx,%eax

    	- sum up the values.  As we add edx to eax, the result is in eax.

    1157:	89 45 fc             	mov    %eax,-0x4(%rbp)

	- put the result to the local variable "n" which happens to be at offset
	  -0x4 from the frame pointer.

	- now, see above, register eax is used in x86 64 ABI for the function
	  return value.  So, by accident, we have the "right" value in the
	  register that is supposed to hold the return value!!!

    115a:	90                   	nop
    115b:	5d                   	pop    %rbp
    115c:	c3                   	retq

000000000000115d <main>:
    115d:	55                   	push   %rbp
    115e:	48 89 e5             	mov    %rsp,%rbp
    1161:	be 63 00 00 00       	mov    $0x63,%esi
    1166:	bf 01 00 00 00       	mov    $0x1,%edi

	- put the values 1 and 99 to the registers representing the 1st and the
	  2nd argument in x86 64 bit ABI

    116b:	e8 d5 ff ff ff       	callq  1145 <addnum>

	- called our function from main()

    1170:	89 c6                	mov    %eax,%esi

	- x86 64 ABI expects the function return value in the register eax, so
	  we just put it to the input register esi representing the 2nd argument
	  for the printf() function.
	- and, given that we happened to have the right value in eax as it was
	  used as a general purpose regirster in the function binary code, our
	  main.c code "works".

    1172:	48 8d 3d 8b 0e 00 00 	lea    0xe8b(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1179:	b8 00 00 00 00       	mov    $0x0,%eax
    117e:	e8 bd fe ff ff       	callq  1040 <printf@plt>
    1183:	b8 00 00 00 00       	mov    $0x0,%eax
    1188:	5d                   	pop    %rbp
    1189:	c3                   	retq
    118a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
```

What if we increment variable `n`, does it change anything?

```C
int
addnum(int n1, int n2)
{
	int n = n1 + n2;
	++n;
}
```
```
$ gcc main.c
./a.out
100
```

Apparently not, let's see the disassembled code:

```
0000000000001145 <addnum>:
    1145:	55                   	push   %rbp
    1146:	48 89 e5             	mov    %rsp,%rbp
    1149:	89 7d ec             	mov    %edi,-0x14(%rbp)
    114c:	89 75 e8             	mov    %esi,-0x18(%rbp)
    114f:	8b 55 ec             	mov    -0x14(%rbp),%edx
    1152:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1155:	01 d0                	add    %edx,%eax
    1157:	89 45 fc             	mov    %eax,-0x4(%rbp)
    115a:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)

    	- OK, the compiler just directly adds 1 to the memory address holding
	  local variable "n".  As it does not change the register eax, it still
	  "works".

    115e:	90                   	nop
    115f:	5d                   	pop    %rbp
    1160:	c3                   	retq
```

So, let's involve another local variable.

```C
int
addnum(int n1, int n2)
{
	int n = n1 + n2;

	int i = 13;
	n = i + n;
}
```
```
$ gcc main.c
$ ./a.out
13
```

Bingo!  It no longer "works".  What happened?

```
0000000000001145 <addnum>:
    1145:	55                   	push   %rbp
    1146:	48 89 e5             	mov    %rsp,%rbp
    1149:	89 7d ec             	mov    %edi,-0x14(%rbp)
    114c:	89 75 e8             	mov    %esi,-0x18(%rbp)
    114f:	8b 55 ec             	mov    -0x14(%rbp),%edx
    1152:	8b 45 e8             	mov    -0x18(%rbp),%eax
    1155:	01 d0                	add    %edx,%eax

    	- this was summing up our two function arguments

    1157:	89 45 f8             	mov    %eax,-0x8(%rbp)

	- the result went to the local variable "n"

    115a:	c7 45 fc 0d 00 00 00 	movl   $0xd,-0x4(%rbp)

	- we initialized local variable "i" (0xd in hexa is 13 in decimal)

    1161:	8b 45 fc             	mov    -0x4(%rbp),%eax

	- See?  Now we used eax for further arithmetic operations.  We just put
	  the current value of local variable "i" to the register.

    1164:	01 45 f8             	add    %eax,-0x8(%rbp)

	- and we added the register value to the present value of local variable
	  "n".  And as 13 was left in eax, that served as the function return
	  value.

    1167:	90                   	nop
    1168:	5d                   	pop    %rbp
    1169:	c3                   	retq
```

:wrench: Try the `clang` compiler and figure out what happened there.

```
$ clang main.c
main.c:7:1: warning: control reaches end of non-void function [-Wreturn-type]
}
^
1 warning generated.
$ ./a.out
0
```

What we should take away from this situation:

- Anything looking as working does not mean it is correct.
- Ideally, if possible, test on different architectures (like x86, SPARC, ARM,
  etc).
- Using different compilers and different systems may help as well.  For
  example, if you develop on a Linux distro with `gcc`, testing it also on a
  macOS laptop would be worth it (C compiler in macOS Xcode IDE is `clang`).
  And what is more, recent MacBook generations are ARM based.
- If something magically stops working that did work before, be ready for
  a possible breakage like this.  Even something that has worked for ages does
  not necessarily mean the code must have been correct to begin with.
- Always use `-Wall -Wextra` GCC options when building your code.  More on that
  later in the seminar.  See that `clang` warns by default which is a good
  thing.

**Do you want more information on x86 ABI and how it really works behind the
scene?** Search for [Solaris Crashdump Analysis Frank
Hofmann](https://duckduckgo.com/?q=Solaris+Crashdump+Analysis+Frank+Hofmann) for
more details.

You probably do not want [all the gory
details](https://upload.wikimedia.org/wikipedia/commons/3/30/AMD_x86-64_Architecture_Programmers_Manuals.jpg)
though...
