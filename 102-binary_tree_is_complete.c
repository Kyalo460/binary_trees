#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root
 *
 * Return: returns 1 if complete
 *         0 if not complete
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nodes, index = 0;

	if (tree == NULL)
		return (0);

	nodes = count_nodes(tree);
	return (completeness_check(tree, index, nodes));
}

/**
 * count_nodes - counts the number of nodes in a binary tree
 * @tree: pointer to the root node
 *
 * Return: returns the number of nodes
*/
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * completeness_check - checks if tree is complete
 * @node: pointer to node of interest
 * @index: current index position
 * @nodes: total number of nodes in the tree
 *
 * Return: returns 1 if complete
 *         0 if not complete
*/
int completeness_check(const binary_tree_t *node, int index, int nodes)
{
	int left, right;

	if (node == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	left = completeness_check(node->left, 2 * index + 1, nodes);
	right = completeness_check(node->right, 2 * index + 2, nodes);

	if (left == right)
		return (1);
	else
		return (0);
}
