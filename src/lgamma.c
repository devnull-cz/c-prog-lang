/*
 * If using functions not only from libc, you need to use -l<libname> to link
 * your code to such a library.  You only use the <libname> name part from
 * lib<libname>.so.  You do not need to use '-lc' for libc, that is the default.
 * For example, you need to link this code with the math library, libm.so.  On
 * Linux and other unix-like systems, many libraries are under /usr/lib.  If
 * using libraries from non-system directories, see the -L/-R/-rpath options to
 * ld(1).
 *
 *	$ cc math.c
 *	/usr/bin/ld: /tmp/ccisQST6.o: in function `main':
 *	math.c:(.text+0x11): undefined reference to `lgamma'
 *	collect2: error: ld returned 1 exit status
 *	$ cc -lm math.c
 *	$
 *
 * See 'man math.h' for more information on the math library.  Note that some
 * functions defined in the library are also in libc, e.g. sqrt(), and using
 * those will not error out on a missing '-lm'.
 *
 * Check with ldd(1) to see libm:
 *
 *	$ ldd a.out 
 *	...
 *	libm.so.6 => /usr/lib/libm.so.6 (0x00007f109f1ab000)
 *	libc.so.6 => /usr/lib/libc.so.6 (0x00007f109efc4000)
 *	...
 */
#include <math.h>
#include <stdio.h>

int
main(void)
{
	printf("%f\n", lgamma(10.0));
}
