#include "binary_trees.h"

/**
 * binary_tree_depth - computes the depth of a node in a tree
 * @tree: a pointer the the root of a tree
 *
 * Return: returns the depth of a node
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
		return (0);

	depth = binary_tree_depth(tree->parent);
	return (depth + 1);
}
