#include "binary_trees.h"


/**
 *binary_tree_size - measures the size of a binary tree.
 *@tree: tree to measure its size.
 *Return: the size of the tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = binary_tree_size(tree->left);
	if (tree->right)
		right = binary_tree_size(tree->right);

	return (1 + left + right);
}
