# Integer to unsigned integer in C89

The C89 specificiation says the following about assigning to an unsigned type:

> Any integer is converted to a given unsigned type by finding
the smallest non-negative value that is congruent to that integer, modulo one
more than the largest value that can be represented in the unsigned type. In a
two's complement representation, this is equivalent to left-truncation if the
bit pattern of the unsigned type is narrower, and to zero-filling unsigned
values and sign-extending signed values if the unsigned type is wider.

What is a congruency relation ? It's quite simple but the language above might
sound complicated. Consult [Congruence
relation](https://en.wikipedia.org/wiki/Congruence_relation).

In our case, the mod part will be either 256 (assigning to char), 65536
(assigning to short), 2^32 (to int or long), or 2^64 (to long or long long).
