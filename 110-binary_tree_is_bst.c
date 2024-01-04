#include "binary_trees.h"
#include <limits.h>

/**
 *binary_tree_is_bst - checks if a binary tree is a valid BST.
 *@tree: Pointer to the tree to check.
 *Return: 0 or 1
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (b_checker(tree, INT_MIN, INT_MAX));
}

/**
 * b_checker - checks if the tree is BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Lower bound of checked node.
 * @max: Upper bound of checked node.
 * Return: 0 or 1
 */
int b_checker(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (b_checker(tree->left, min, tree->n - 1) &&
		b_checker(tree->right, tree->n + 1, max));
}
