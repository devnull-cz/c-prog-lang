# compile all source files.
# Requires GNU make.

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99

OBJDIR=objs
BLACKLIST=./const-not-really-a-const.c \
	./ternary.c \
	./array-var-not-modifiable.c \
	./const.c \
	./common-mistake-with-define.c \
	./const-and-pointers.c
SRCS_ORIG=$(shell find . -type f -name '*.c')
SRCS=$(filter-out $(BLACKLIST),$(SRCS_ORIG))
OBJS=$(SRCS:c=o)
OBJNAMES=$(subst ./,,$(OBJS))
DIROBJS=$(addprefix $(OBJDIR)/,$(OBJNAMES))

# overrides
$(OBJDIR)/ext.o: CFLAGS_EXTRA = -Wno-unused-variable
$(OBJDIR)/int-to-ptr.o: CFLAGS_EXTRA = -Wno-int-conversion -Wno-unused-variable
$(OBJDIR)/cast-double.o: CFLAGS_EXTRA = -Wno-format
$(OBJDIR)/struct-anon.o: CFLAGS_EXTRA = -Wno-c11-extensions
$(OBJDIR)/array-literal.o: CFLAGS_EXTRA = -Wno-sign-compare
$(OBJDIR)/plus-deref-plus-deref-argv.o: CFLAGS_EXTRA = -Wno-format \
	-Wno-unused-parameter
$(OBJDIR)/range-check.o: CFLAGS_EXTRA = -Wno-sign-compare
$(OBJDIR)/fahr-to-cent.o: CFLAGS_EXTRA = -Wno-unused-variable
$(OBJDIR)/static_assert.o: CFLAGS_EXTRA = -Wno-int-to-void-pointer-cast \
	-Wno-unused-local-typedef
$(OBJDIR)/compound-statement-invalid.o: CFLAGS_EXTRA = \
	-Wno-gnu-statement-expression
$(OBJDIR)/ptr-inc.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/no-return.o: CFLAGS_EXTRA = -Wno-return-type
$(OBJDIR)/array-designated-initializers.o: CFLAGS_EXTRA = -Wno-gnu-designator
$(OBJDIR)/ptr-to-array-of-ptrs.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/implement-function.o: CFLAGS_EXTRA = \
	-Wno-implicit-function-declaration -Wno-format
$(OBJDIR)/static-func.o: CFLAGS_EXTRA = -Wno-unused-function
$(OBJDIR)/cast-intptr.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/print-argv-recursively.o: CFLAGS_EXTRA = -Wno-unused-parameter
$(OBJDIR)/3d-array.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/2d-array.o: CFLAGS_EXTRA = -Wno-sign-compare
$(OBJDIR)/struct-designated-init.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/expression-statement.o: CFLAGS_EXTRA = -Wno-unused-value
$(OBJDIR)/ptr-ptr-array.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/argv-nodash.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/bitwise-vs-logical.o: CFLAGS_EXTRA = -Wno-parentheses
$(OBJDIR)/argv-while.o: CFLAGS_EXTRA = -Wno-format-pedantic \
	-Wno-unused-parameter
$(OBJDIR)/random.o: CFLAGS_EXTRA = -Wno-sign-compare
$(OBJDIR)/plus-deref-plus-argv.o: CFLAGS_EXTRA = -Wno-unused-parameter
$(OBJDIR)/struct-op-precedence.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/empty-array.o: CFLAGS_EXTRA = -Wno-zero-length-array
$(OBJDIR)/hello-world1.o: CFLAGS_EXTRA = -Wno-implicit-function-declaration
$(OBJDIR)/assert.o: CFLAGS_EXTRA = -Wno-unused-parameter
$(OBJDIR)/argv-for.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/buf-overflow.o: CFLAGS_EXTRA = -Wno-builtin-memcpy-chk-size
$(OBJDIR)/derived-types.o: CFLAGS_EXTRA = -Wno-incompatible-pointer-types
$(OBJDIR)/ptr_plus_plus.o: CFLAGS_EXTRA = -Wno-format-pedantic -Wno-unused-value
$(OBJDIR)/arithmetics2.o: CFLAGS_EXTRA = -Wno-format
$(OBJDIR)/struct-reference.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/null-ptr.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/ptr-basics.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/string-const-address.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/prefix-ptr-inc.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/uintptr.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/ptr-change.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/ptr-diff.o: CFLAGS_EXTRA = -Wno-format-pedantic
$(OBJDIR)/printf-format.o: CFLAGS_EXTRA = -Wno-format
$(OBJDIR)/wrong-modifier.o: CFLAGS_EXTRA = -Wno-format
$(OBJDIR)/fmt-string-invalid.o: CFLAGS_EXTRA = -Wno-format
$(OBJDIR)/printf2.o: CFLAGS_EXTRA = -Wno-format
$(OBJDIR)/bytecnt2str.o: CFLAGS_EXTRA = -Wno-unused-parameter
$(OBJDIR)/conway-1d-30.o: CFLAGS_EXTRA = -Wno-sign-compare
$(OBJDIR)/integer-conversion.o: CFLAGS_EXTRA = -Wno-constant-conversion
$(OBJDIR)/array-as-argument.o: CFLAGS_EXTRA = -Wno-sizeof-array-argument \
	-Wno-format-pedantic
$(OBJDIR)/sequence-point-violation.o: CFLAGS_EXTRA = -Wno-unsequenced \
	-Wno-uninitialized
$(OBJDIR)/ptr-cast.o: CFLAGS_EXTRA = -Wno-incompatible-pointer-types
$(OBJDIR)/complex-declaration.o: CFLAGS_EXTRA = -Wno-missing-braces \
	-Wno-tautological-compare
$(OBJDIR)/passing-arrays.o: CFLAGS_EXTRA = -Wno-incompatible-pointer-types \
	-Wno-uninitialized -Wno-unused-parameter
$(OBJDIR)/whole-array.o: CFLAGS_EXTRA = -Wno-sign-compare

all: $(DIROBJS)

$(OBJDIR)/%.o: %.c
	$(CC) -o $@ $(CFLAGS) $(CFLAGS_EXTRA) -c $<

clean:
	rm -f *.o $(OBJDIR)/*.o

.PHONY: clean
