#include "binary_trees.h"

/**
 * binary_tree_nodes - computes the number of parents in binary tree
 * @tree: the root/parent of a tree
 *
 * Return: returns the number of parents in a tree
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t parents = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		parents = 1;

	parents += binary_tree_nodes(tree->left);
	parents += binary_tree_nodes(tree->right);

	return (parents);
}
