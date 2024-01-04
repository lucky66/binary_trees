#include "binary_trees.h"

/**
 *bst_insert - inserts a value in a Binary Search Tree.
 *@tree: Double pointer to the root node of the BST.
 *@value: Value to store in the node..
 *Return: Pointer to the newly created node.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new = binary_tree_node(NULL, value), *tmp;
	int node_value;

	if (!tree)
		return (NULL);
	if (!*tree)
		*tree = new;
	else
	{
		tmp = *tree;
		while (tmp)
		{
			node_value = tmp->n;
			if (value < node_value)
			{
				if (!tmp->left)
				{
					tmp->left = new;
					new->parent = tmp;
					break;
				}
				tmp = tmp->left;

			}
			else if (value > node_value)
			{
				if (!tmp->right)
				{
					tmp->right = new;
					new->parent = tmp;
					break;
				}
				tmp = tmp->right;
			}
			else if (value == node_value)
				return (NULL);
		}
	}
	return (new);
}
