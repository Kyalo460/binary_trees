#include "binary_trees.h"

/**
 * binary_tree_levelorder - prints a binary tree using level-order traversal
 * @tree: pointer to the root of a tree
 * @func: pointer to a function that prints the value in a node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
	{
		print_node(tree, i, func);
	}
}

/**
* print_node - prints the node values in level-order
* @root: pointer to a node
* @level: a number that represents the level of a node in a tree
* @func: pointer to function that prints the value of a node
*/
void print_node(const binary_tree_t *root, size_t level, void (*func)(int))
{
	if (!root)
		return;

	if (level == 0)
		func(root->n);
	else
	{
		print_node(root->left, (level - 1), func);
		print_node(root->right, (level - 1), func);
	}
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
