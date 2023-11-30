#include "binary_trees.h"

/**
 * binary_tree_balance - computes the balnce factor of a tree/subtree
 * @tree: pointer to the root node
 *
 * Return: returns the balance factor
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0, left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->right == NULL)
		return (1);

	if (tree->right && !tree->left)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	balance_factor = left_height - right_height;

	return (balance_factor);
}

/**
 * binary_tree_height - computes the height of a tree
 * @tree: a pointer to the root of a tree
 *
 * Return: returns the height of a tree
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	else
		return (right_height + 1);
}
