# bitwise operators vs. logical operators vs. comparison

Bit operators have lower precedence than comparison.  As a consequence the
evaluation of expressions such as `(a & b == c & d)` is counter intuitive.

#source bitwise-vs-logical.c

In this case modern compilers (clang) will actually warn about missing
parentheses.

You can read the explaination by Dennis Ritchie here:
http://www.lysator.liu.se/c/dmr-on-or.html
