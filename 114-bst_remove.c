#include "binary_trees.h"

/**
 *bst_remove - removes a node from a Binary Search Tree.
 *@root: Pointer to the root node of the tree to remove a node.
 *@value: Value of the node to remove in the tree.
 *Return: Pointer to the new root node of the tree.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		tmp = lowest_node(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 *lowest_node - Returns the node with the lowest value from BST.
 *@root: Pointer to the root node of the tree.
 *Return: Pointer to the node.
 */
bst_t *lowest_node(bst_t *root)
{
	bst_t *lowest = root;

	while (lowest->left)
		lowest = lowest->left;

	return (lowest);
}
