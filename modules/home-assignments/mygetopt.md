# Home assignment: mygetopt

implement a command line parser ala getopt(3). The global variable
'myoptarg' will be set if an option has an argument.

Note: call the function `mygetopt()` not to intermingle with the standard
library's `getopt()`.  Implement the "POSIXly correct solution", i.e. stop once
non-option argument is encountered (i.e. one not starting with `-`) or after the
`--` option is reached.

:wrench: bonus task: implement myoptind/myopterr/myoptopt variables

See the following code on how to use getopt(3):

https://github.com/devnull-cz/unix-linux-prog-in-c-src/blob/master/getopt/getopt.c

