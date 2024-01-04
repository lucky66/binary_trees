#include "binary_trees.h"


/**
 *bst_search - searches for a value in a Binary Search Tree.
 *@tree: Pointer to the root node of the tree to search.
 *@value: Value to search for.
 *Return: Pointer to the node with the given value.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	while (tree)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		else if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return (NULL);
}
