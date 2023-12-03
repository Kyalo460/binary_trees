#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_trees_ancestor - finsds the earliest ancestor of two nodes
 * @first: pointer to one node
 * @second: pointer to the other node
 *
 * Return: returns the ancestor if found or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth, i, depth_diff;
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	depth_diff = second_depth - first_depth;

	if (first_depth > second_depth)
	{
		depth_diff = first_depth - second_depth;
		temp = first;
		first = second;
		second = temp;
	}
	if (first_depth != second_depth)
	{
		for (i = 0; i < depth_diff; i++)
		{
		if (second->parent)
			second = second->parent;
		else
			return (NULL);
		}
	}

	while (first)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}

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
