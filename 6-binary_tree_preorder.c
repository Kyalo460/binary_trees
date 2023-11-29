#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_preorder - traverses a binary tree preorderly
 * @tree: the root of the tree
 * @func: pointer to a function that prints value of a node
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
