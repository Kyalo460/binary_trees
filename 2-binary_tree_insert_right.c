#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_insert_left - makes a new node on the left side of a parent node
 * @parent: parent of the new node
 * @value: value for the new node
 * 
 * Return: NULL if failure
 *         pointer to new node if success
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (parent == NULL)
		return (NULL);
    
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
    
	new->n = value;
	new->parent = parent;
	new->right = parent->right;
	parent->right = new;
	new->left = NULL;

	return (new);
}