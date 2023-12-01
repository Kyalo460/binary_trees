#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if a tree is a perfect tree
 * @tree: pointer to the root node
 *
 * Return: returns 1 if perfect
 *         returns 0 if not perfect
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int balanced = 0, full = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		balanced += binary_tree_balance(tree->left);
	if (tree->right)
		balanced += binary_tree_balance(tree->right);

	balanced += binary_tree_balance(tree);
	if (balanced != 0)
		return (0);

	full = binary_tree_is_full(tree);
	if (full != 1)
		return (0);

	return (1);
}

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
		return (binary_tree_height(tree));

	if (tree->right && !tree->left)
		return (-(binary_tree_height(tree)));

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
