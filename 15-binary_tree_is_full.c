#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a tree or subtree is full
 * @tree: pointer to the root node
 *
 * Return: returns 0 if not full
 *         returns 1 if full
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int right = 0, left = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && !tree->right)
		return (0);
	if (tree->right && !tree->left)
		return (0);

	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);

	if (left != 1 || right != 1)
		return (0);
	return (1);
}
