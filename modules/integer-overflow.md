# Integer overflow

- what happens if `int` overflows ?
  - the behavior of overflow depends on whether the type is signed or unsigned
    - :heavy\_exclamation\_mark: for signed types the behavior is **undefined**!
      I.e. you cannot rely that an overflow of a positive quantity in any signed
      integer will be turned into a negative number.
      - Some compilers will allow to choose the behavior of signed overflows
	using special options (`-fwrapv` for GCC), though.
    - for unsigned integers, an overflow always wraps around (modulo power of 2)
      as it is defined behavior.

  #source int-overflow.c
  #source unsigned-overflow.c

    - use `-fstrict-overflow -Wstrict-overflow` (will become active only for
      higher optimization levels, i.e. `-O<X>` where `X > 1`) to stay on the
      safe side
