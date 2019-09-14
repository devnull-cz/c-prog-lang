/*
 * Create a set of functions for manipulating a linked list.  The program
 * accepts input commands as command line arguments and executes them.  New
 * elements are always appended to the list and any item is always removed from
 * the head.  Keep pointers to the first list item (head) and the last one
 * (tail).
 *
 * Commands are: create a list, insert an item, remove an item, and print the
 * list.  It is mandatory to create a list before doing anything else.
 *
 *   create a list:		C
 *   insert an item:		I<nnn>
 *   remove an item:		R
 *   print a list:		P
 *
 * Do reasonable checking for dealing with invalid input.  See below.
 *
 * Example:
 *
 *   $ ./a.out C I1 I2 I3 I4 I5 P R P I6 P I7 P R P R P R P R R R P I88 P R P
 *   List: 1 2 3 4 5
 *   List: 2 3 4 5
 *   List: 2 3 4 5 6
 *   List: 2 3 4 5 6 7
 *   List: 3 4 5 6 7
 *   List: 4 5 6 7
 *   List: 5 6 7
 *   List: EMPTY
 *   List: 88
 *   List: EMPTY
 *
 *   $ ./a.out C R
 *   a.out: Cannot remove an item from an empty list.
 *
 *   $ ./a.out C P
 *   List: EMPTY
 *
 *   $ ./a.out C L
 *   a.out: Wrong command: L
 *
 *   $ ./a.out C C
 *   a.out: List already created, exiting.
 *
 *   $ ./a.out I88
 *   a.out: List not created yet.
 */

#include <sys/types.h>
#include <stdio.h>
#include <err.h>
#include <libgen.h>
#include <stdlib.h>
#include <assert.h>

/* Set LLIST_DEBUG env variable to get some debug. */
int dbg;
int list_created = 0;

struct litem {
	int n;
	struct litem *next;
};

struct llist {
	struct litem *head;
	struct litem *tail;
};

struct llist l;

void
check_list_existence(void)
{
	if (!list_created)
		errx(1, "List not created yet.");
}

void
create_list(void)
{
	if (list_created)
		errx(1, "List already created, exiting.");

	/* Nothing really needed here to create a list. */
	if (dbg == 1)
		printf("Creating list.\n");
	list_created = 1;
}

void
insert_item(int num)
{
	struct litem *new;

	new = malloc(sizeof (struct litem));
	assert(new != NULL);
	new->n = num;
	new->next = NULL;

	if (l.head == NULL) {
		l.head = l.tail = new;
		return;
	}
	l.tail->next = new;
	l.tail = new;
}

void
remove_item(void)
{
	struct litem *old;

	if (l.head == NULL)
		errx(1, "Cannot remove an item from an empty list.");

	old = l.head;
	l.head = l.head->next;
	free(old);
}

void
print_list(void)
{
	struct litem *i = l.head;

	if (dbg == 1)
		printf("Will print the list.\n");

	printf("List:");
	if (i == NULL) {
		printf(" EMPTY\n");
		return;
	}

	while (i->next != NULL) {
		printf (" %d", i->n);
		i = i->next;
	}
	printf (" %d\n", i->n);
}

int
main(int argc, char **argv)
{
	int i = 1;

	if (argc == 1)
		errx(1, "Usage: %s <commands>", basename(argv[0]));

	if (getenv("LLIST_DEBUG") != NULL)
		dbg = 1;

	while (i < argc) {
		switch (argv[i][0]) {
		case 'C':
			create_list();
			break;
		case 'P':
			check_list_existence();
			print_list();
			break;
		case 'I':
			check_list_existence();
			insert_item(atoi(argv[i] + 1));
			break;
		case 'R':
			check_list_existence();
			remove_item();
			break;
		default:
			errx(1, "Wrong command: %c", argv[i][0]);
		}
		i++;
	}

	return (0);
}
