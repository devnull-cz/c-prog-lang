/*
 * Create tree of paths, where each node is path element. The tree starts
 * with root '/', the leaves are files. The three can look e.g. like this:
 *
 *                       "/"
 *		       /  |   \
 *		      /   |     \
 *		  "foo/" "f.txt"  "bar/"
 *		  /   \
 *		"a.c" "b.c"
 *
 * Populate the tree with given paths and print the leaves
 * (no particular order). Then free the allocated memory.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define	MAX_CHILDREN	8

struct node_s {
	char *elem;
	struct node_s *children[MAX_CHILDREN];
	unsigned int num_child;
};

typedef struct node_s node_t;

node_t *root;


node_t *
get_child_node(node_t *n, char *str)
{
	unsigned int i = 0;
	node_t *nn = NULL;

	while (i < n->num_child) {
		nn = n->children[i];
		if (strcmp(nn->elem, str) == 0) {
#ifdef DEBUG
			printf("found '%s'\n", str);
#endif
			return (nn);
		}
		i++;
	}

	return (NULL);
}

static node_t *
alloc_node(char *elem)
{
	node_t *n = malloc(sizeof (node_t));
	assert(n != NULL);
	n->elem = malloc(strlen(elem) + 1);
	assert(n->elem != NULL);
	strcpy(n->elem, elem);
	memset(n->children, 0, sizeof (n->children));
	n->num_child = 0;

	return (n);
}

static void
add_child(node_t *parent, node_t *child)
{
#ifdef DEBUG
	printf("adding child '%s' to parent '%s'\n",
	    child->elem, parent->elem);
#endif
	assert(parent->num_child < MAX_CHILDREN);
	parent->children[parent->num_child++] = child;
}

void
add(char *path)
{
	char *pelem;
	node_t *n = root;
	// copy the string to avoid bus error on writing to read-only memory.
	char *p = malloc(strlen(path) + 1);
	assert(p != NULL);
	strcpy(p, path);
	char *porig = p;

	printf("adding path '%s'\n", path);

	char *brkt;
	for (pelem = strtok_r(p, "/", &brkt); pelem != NULL;
            pelem = strtok_r(NULL, "/", &brkt)) {
		if (pelem[0] != '\0') {
			printf("  adding path element '%s'\n", pelem);
			node_t *nn;
			if ((nn = get_child_node(n, pelem)) != NULL) {
				n = nn;
			} else {
				node_t *new_node = alloc_node(pelem);
				add_child(n, new_node);
				n = new_node;
			}
		}
	}

	free(porig);
}

static void
populate(char *paths[], size_t nitems)
{
	for (size_t i = 0; i < nitems; i++) {
		char *path = paths[i];
		assert(path[0] == '/');

		add(path);
	}
}

static void
free_node(node_t *node)
{
#ifdef DEBUG
	printf("freeing node '%s'\n", node->elem);
#endif
	free(node->elem);
	node->elem = NULL;
	node->num_child = 0;
	free(node);
}

static void
tree_traverse(node_t *n)
{
	if (n->num_child == 0)
		printf("%s\n", n->elem);
	for (unsigned int i = 0; i < n->num_child; i++)
		tree_traverse(n->children[i]);
}

static void
tree_free(node_t *n)
{
	for (unsigned int i = 0; i < n->num_child; i++)
		tree_free(n->children[i]);

	free_node(n);
}

int
main(void)
{
	char *paths[] = { "/beverages/coffee/espresso.java",
			"/beverages/alcohol/beer.c",
			"/food/healthy/vegetarian/salad.txt",
			"/food/healthy/fruit/blueberries.hs",
			"/food/unhealthy/cake.md" };

	root = alloc_node("/");

	populate(paths, sizeof (paths) / sizeof (paths[0]));
	tree_traverse(root);
	tree_free(root);
}
