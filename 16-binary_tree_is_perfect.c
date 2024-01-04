#include "binary_trees.h"
#include <stddef.h>

/**
 *binary_tree_is_perfect - checks if a binary tree is perfect.
 *@tree: Pointer to the root node ofthe tree to check.
 *Return: 0 if not perfect, 1 if otherwise.
 *
 * 2^(h + 1) - 1 = n
 * Where:
 *	h is the height of the binary tree.
 *	n is the total number of nodes in the binary tree.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t is_perfect, height, total_nodes;

	if (!tree)
		return (0);

	height = (size_t)tree_height(tree);
	total_nodes = tree_size(tree);

	is_perfect = custom_pow(2, height + 1) - 1;
	return (is_perfect == total_nodes);
}

/**
 *tree_height - Gets the height of a tree.
 *@tree: Pointer to the root node of the tree.
 *Return: The height of the tree.
 */

int tree_height(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = 1 + tree_height(tree->left);
	if (tree->right)
		right = 1 + tree_height(tree->right);

	return (left > right ? left : right);
}

/**
 *tree_size - measures the size of a binary tree.
 *@tree: tree to measure its size.
 *Return: the size of the tree.
 */

size_t tree_size(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left = tree_size(tree->left);

	if (tree->right)
		right = tree_size(tree->right);

	return (1 + left + right);
}

/**
 *custom_pow - calculates the power of a number.
 *@base: Number.
 *@exponent: Exponent.
 *Return: Power of the given number.
 */
size_t custom_pow(size_t base, size_t exponent)
{
	size_t i, result = 1;

	if (exponent == 0)
		return (1);

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return (result);
}
