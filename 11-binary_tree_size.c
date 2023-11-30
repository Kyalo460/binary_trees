#include "binary_trees.h"

/**
 * binary_tree_size - computes the number of nodes in a tree / sub-tree
 * @tree: a pointer to the root of a binary tree
 *
 * Return: retuurns the size of the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}
