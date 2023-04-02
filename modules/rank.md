## Integer conversion rank

See *6.3.1.1 Boolean, characters, and integers* for the full list.

Every integer type has an *integer conversion rank* defined as follows:

- No two signed integer types shall have the same rank, even if they have the
  same representation.
- The rank of a signed integer type shall be greater than the rank of any
  signed integer type with less precision.
- The rank of `long long int` shall be greater than the rank of `long int`,
  which shall be greater than the rank of `int`, which shall be greater than the
  rank of `short int`, which shall be greater than the rank of `signed char`.
- The rank of any unsigned integer type shall equal the rank of the
  corresponding signed integer type, if any.
- The rank of `char` shall equal the rank of `signed char` and `unsigned char`.
- The rank of `_Bool` shall be less than the rank of all other standard integer
  types.
- The rank of any enumerated type shall equal the rank of the compatible integer
  type (see 6.7.2.2).
