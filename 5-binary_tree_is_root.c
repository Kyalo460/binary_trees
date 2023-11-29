#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_root - checks if node is the root of a binary tree
 * @node: the node to test
 *
 * Return: returns 1 if root
 *         returns 0 otherwise
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->parent == NULL)
		return (1);

	return (0);
}
