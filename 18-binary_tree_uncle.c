#include "binary_trees.h"


/**
 *binary_tree_uncle - finds the uncle of a node.
 *@node: Pointer to the node to find its uncle.
 *Return: Pointer to the uncle none or NULL.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *node_parent;

	if (!node)
		return (NULL);

	node_parent = node->parent;
	if (!node_parent || !node_parent->parent)
		return (NULL);

	if (node_parent->parent->left == node_parent)
		return (node_parent->parent->right);
	return (node_parent->parent->left);
}
