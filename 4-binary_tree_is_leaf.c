#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - checks if a node in a tree is a leaf
 * @node: the node to test
 * 
 * Return: returns 1 if node is a leaf
 *         returns 0 otherwise
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);

	return (0);
}