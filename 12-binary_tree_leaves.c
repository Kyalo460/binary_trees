#include "binary_trees.h"

/**
 * binary_tree_leaves - computes the number of leaves in a binary tree
 * @tree: a pointer to the root/parent node
 *
 * Return: returns the number of leaves
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (leaves + 1);

	leaves += binary_tree_leaves(tree->left);
	leaves += binary_tree_leaves(tree->right);

	return (leaves);
}
