#include "binary_trees.h"


/**
 *binary_tree_leaves - counts the leaves in a binary tree.
 *@tree: Pointer to the tree to count the leaves.
 *Return: number of leaves in the tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return (left + right);
}
