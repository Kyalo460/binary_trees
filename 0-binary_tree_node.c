#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tress_node - makes a node that has a parent pointer and value
 * @parent: the parent of the node to create
 * @value: the value to assign to the new node
 * 
 * Return: returns a pointer to the new node
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
    
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;

	return (new);
}