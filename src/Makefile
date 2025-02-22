# compile all source files.
# Requires GNU make and Git + Git checkout of the repository.
# Supports Linux and macOS.

CFLAGS=-Wall -Werror -Wextra -pedantic -std=c99

ifeq ($(CC),cc)
CC_VERSION=$(shell cc --version | head -1)
ifeq (clang,$(findstring clang,$(CC_VERSION)))
CC=clang
else
CC=gcc
endif
endif

UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
OS=linux
else ifeq ($(UNAME_S),Darwin)
OS=macos
endif

OBJDIR=objs

#
# These sources lead to warnings or errors. These are filtered out,
# i.e. not compiled.
#
BLACKLIST=const-not-really-a-const.c \
	ternary.c \
	array-var-not-modifiable.c \
	const.c \
	common-mistake-with-define.c \
	const-and-pointers.c \
	hello-world1.c \
	empty-array.c \
	printf.c \
	error.c \
	integer-conversion-assignment.c \
	ptr-lvalue.c \
	pointer-to-array-type-difference.c \
	print-int-as-double.c

SRCS_ORIG=$(shell git ls-files '*.c')
SRCS=$(filter-out $(BLACKLIST),$(SRCS_ORIG))
OBJS=$(SRCS:c=o)
OBJNAMES=$(subst ./,,$(OBJS))
DIROBJS=$(addprefix $(OBJDIR)/,$(OBJNAMES))

# overrides
$(OBJDIR)/ext.o: CFLAGS_EXTRA=-Wno-unused-variable
$(OBJDIR)/int-to-ptr.o: CFLAGS_EXTRA=-Wno-int-conversion -Wno-unused-variable
$(OBJDIR)/cast-double.o: CFLAGS_EXTRA=-Wno-format
$(OBJDIR)/struct-anon.o: CFLAGS_EXTRA=-Wno-c11-extensions -Wno-pedantic
$(OBJDIR)/array-literal.o: CFLAGS_EXTRA=-Wno-sign-compare
ifeq ($(CC), gcc)
$(OBJDIR)/argv-do-while.o: CFLAGS_EXTRA=-Wno-error=unused-parameter
else ifeq ($(CC), clang)
$(OBJDIR)/argv-do-while.o: CFLAGS_EXTRA=-Wno-error=unused-parameter -Wno-error=format-pedantic
endif
$(OBJDIR)/argv-for-v2.o: CFLAGS_EXTRA=-Wno-error=unused-parameter
$(OBJDIR)/argv-while-v2.o: CFLAGS_EXTRA=-Wno-error=unused-parameter
$(OBJDIR)/plus-deref-plus-deref-argv.o: CFLAGS_EXTRA=-Wno-format \
	-Wno-unused-parameter
$(OBJDIR)/range-check.o: CFLAGS_EXTRA=-Wno-sign-compare
$(OBJDIR)/fahr-to-cent.o: CFLAGS_EXTRA=-Wno-unused-variable
$(OBJDIR)/static_assert.o: CFLAGS_EXTRA=-Wno-int-to-void-pointer-cast \
	-Wno-unused-local-typedef -Wno-int-to-pointer-cast \
	-Wno-unused-local-typedefs
$(OBJDIR)/compound-statement-invalid.o: CFLAGS_EXTRA=\
	-Wno-gnu-statement-expression -Wno-pedantic
$(OBJDIR)/ptr-inc.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/no-return.o: CFLAGS_EXTRA=-Wno-return-type
$(OBJDIR)/why-it-works.o: CFLAGS_EXTRA=-Wno-return-type -Wno-unused-variable
$(OBJDIR)/array-designated-initializers.o: CFLAGS_EXTRA=-Wno-gnu-designator \
	-Wno-pedantic
$(OBJDIR)/ptr-to-array-of-ptrs.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-format
$(OBJDIR)/tasks/string-to-array-copy.o: CFLAGS_EXTRA=\
	-Wno-implicit-function-declaration -Wno-format
$(OBJDIR)/static-func.o: CFLAGS_EXTRA=-Wno-unused-function
$(OBJDIR)/cast-intptr.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/print-argv-recursively.o: CFLAGS_EXTRA=-Wno-unused-parameter
$(OBJDIR)/3d-array.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/2d-array.o: CFLAGS_EXTRA=-Wno-sign-compare
$(OBJDIR)/struct-designated-init.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-format
$(OBJDIR)/expression-statement.o: CFLAGS_EXTRA=-Wno-unused-value
$(OBJDIR)/ptr-ptr-array.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/argv-nodash.o: CFLAGS_EXTRA=-Wno-format-pedantic
$(OBJDIR)/bitwise-vs-logical.o: CFLAGS_EXTRA=-Wno-parentheses
$(OBJDIR)/argv-while.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-unused-parameter
$(OBJDIR)/random.o: CFLAGS_EXTRA=-Wno-sign-compare
$(OBJDIR)/plus-deref-plus-argv.o: CFLAGS_EXTRA=-Wno-unused-parameter
$(OBJDIR)/struct-op-precedence.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-format
$(OBJDIR)/empty-array.o: CFLAGS_EXTRA=-Wno-zero-length-array
$(OBJDIR)/assert.o: CFLAGS_EXTRA=-Wno-unused-parameter
$(OBJDIR)/my-assert.o: CFLAGS_EXTRA=-Wno-unused-parameter
$(OBJDIR)/argv-for.o: CFLAGS_EXTRA=-Wno-format-pedantic
ifeq ($(CC), gcc)
$(OBJDIR)/buf-overflow.o: CFLAGS_EXTRA=-Wno-builtin-memcpy-chk-size \
	-Wno-sizeof-pointer-memaccess -Wno-stringop-overflow
else
$(OBJDIR)/buf-overflow.o: CFLAGS_EXTRA=-Wno-builtin-memcpy-chk-size \
	-Wno-sizeof-pointer-memaccess
endif
$(OBJDIR)/derived-types.o: CFLAGS_EXTRA=-Wno-incompatible-pointer-types
$(OBJDIR)/ptr_plus_plus.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-unused-value -Wno-format
$(OBJDIR)/arithmetics2.o: CFLAGS_EXTRA=-Wno-format
ifeq ($(CC), gcc)
$(OBJDIR)/arithmetics.o: CFLAGS_EXTRA=-Wno-unused-but-set-variable
endif
$(OBJDIR)/struct-reference.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/null-ptr.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/ptr-basics.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/string-literal-address.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-format
$(OBJDIR)/prefix-ptr-inc.o: CFLAGS_EXTRA=-Wno-format-pedantic \
	-Wno-format
$(OBJDIR)/uintptr.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/ptr-change.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/ptr-diff.o: CFLAGS_EXTRA=-Wno-format-pedantic -Wno-format
$(OBJDIR)/printf-format.o: CFLAGS_EXTRA=-Wno-format
$(OBJDIR)/wrong-modifier.o: CFLAGS_EXTRA=-Wno-format
$(OBJDIR)/fmt-string-invalid.o: CFLAGS_EXTRA=-Wno-format
$(OBJDIR)/printf2.o: CFLAGS_EXTRA=-Wno-format
$(OBJDIR)/bytecnt2str.o: CFLAGS_EXTRA=-Wno-unused-parameter
$(OBJDIR)/conway-1d-30.o: CFLAGS_EXTRA=-Wno-sign-compare
ifeq ($(CC), clang)
$(OBJDIR)/integer-conversion.o: CFLAGS_EXTRA=-Wno-constant-conversion
else ifeq ($(CC), gcc)
$(OBJDIR)/integer-conversion.o: CFLAGS_EXTRA=-Wno-overflow
endif
ifeq ($(CC), clang)
$(OBJDIR)/array-as-argument.o: CFLAGS_EXTRA=-Wno-sizeof-array-argument \
	-Wno-format-pedantic
else ifeq ($(CC), gcc)
$(OBJDIR)/array-as-argument.o: CFLAGS_EXTRA=-Wno-sizeof-array-argument \
	-Wno-format-pedantic -Wno-stringop-overflow
endif
$(OBJDIR)/sequence-point-violation.o: CFLAGS_EXTRA=-Wno-unsequenced \
	-Wno-uninitialized -Wno-sequence-point
$(OBJDIR)/ptr-cast.o: CFLAGS_EXTRA=-Wno-incompatible-pointer-types
ifeq ($(CC), gcc)
$(OBJDIR)/complex-declaration.o: CFLAGS_EXTRA=-Wno-missing-braces \
	-Wno-tautological-compare -Wno-array-compare
else
$(OBJDIR)/complex-declaration.o: CFLAGS_EXTRA=-Wno-missing-braces \
	-Wno-tautological-compare
endif
$(OBJDIR)/passing-arrays.o: CFLAGS_EXTRA=-Wno-incompatible-pointer-types \
	-Wno-uninitialized -Wno-unused-parameter
$(OBJDIR)/whole-array.o: CFLAGS_EXTRA=-Wno-sign-compare
$(OBJDIR)/signed-plus-unsigned.o: CFLAGS_EXTRA=-Wno-sign-compare
# DEFAULT_SOURCE is Linux only
ifeq ($(OS), linux)
$(OBJDIR)/strsep.o: CFLAGS_EXTRA=-D_DEFAULT_SOURCE
endif
ifeq ($(OS), linux)
$(OBJDIR)/random.o: CFLAGS_EXTRA=-D_DEFAULT_SOURCE -Wno-sign-compare
endif
ifeq ($(CC), gcc)
$(OBJDIR)/typedef.o: CFLAGS_EXTRA=-Wno-unused-but-set-variable
endif
$(OBJDIR)/int-promotion.o: CFLAGS_EXTRA=-Wno-overflow
$(OBJDIR)/divbyzero.o: CFLAGS_EXTRA=-Wno-unused-but-set-variable
$(OBJDIR)/divminus.o: CFLAGS_EXTRA=-Wno-unused-but-set-variable
$(OBJDIR)/typedef.o: CFLAGS_EXTRA=-Wno-unused-but-set-variable
ifeq ($(CC), gcc)
$(OBJDIR)/use-after-free.o: CFLAGS_EXTRA=-Wno-use-after-free
endif
$(OBJDIR)/func-implicit.o: CFLAGS_EXTRA=-Wno-strict-prototypes
ifeq ($(CC), clang)
$(OBJDIR)/shadow-block.o: CFLAGS_EXTRA=-Wno-unused-but-set-variable
endif

all: $(DIROBJS)

$(OBJDIR)/%.o: %.c
	$(CC) -o $@ $(CFLAGS) $(CFLAGS_EXTRA) -c $<

clean:
	rm -f *.o $(OBJDIR)/*.o

.PHONY: clean
