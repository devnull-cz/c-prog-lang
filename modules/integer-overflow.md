# Integer overflow

- what happens if `int` overflows ?
  - the behavior of overflow depends on whether the type is signed or unsigned
    - for signed types the behavior is undefined!  I.e. you cannot rely on
      overflow of a positive quantity in a signed int will be turned into
      a negative number.  Some compilers will allow to specify the behavior of
      signed overflows using special options (`-fwrapv` for GCC), though.
    - for unsigned, an overflow always wraps around (modulo power of 2) and is a
      defined behavior.

  code: :eyes: [int-overflow.c](/src/int-overflow.c),
  [unsigned-overflow.c](/src/unsigned-overflow.c)

    - use `-fstrict-overflow -Wstrict-overflow` (will become active only for
      higher optimization levels, i.e. `-O<X>` where `X > 1`) to stay on the
      safe side
