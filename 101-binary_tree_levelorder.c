#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using.
 * level-order traversal.
 * @tree: tree to traverse.
 * @func: function to call on each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t step, height;

	if (!tree || !func)
		return;

	height = t_height(tree) + 1;

	for (step = 1; step <= height; step++)
		o_level(tree, func, step);
}

/**
 * o_level - Prints binary tree in post-order order.
 * @tree: tree to traverse..
 * @func: function to call on each node.
 * @step: the current step or level in the tree being traversed.
 */
void o_level(const binary_tree_t *tree, void (*func)(int), size_t step)
{
	if (step == 1)
	{
		func(tree->n);
		return;
	}
	o_level(tree->left, func, step - 1);
	o_level(tree->right, func, step - 1);
}

/**
 *t_height - Gets the height of a tree.
 *@tree: The tree.
 *Return: height of the tree.
 */
size_t t_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	left = tree->left ? 1 + t_height(tree->left) : 0;
	right = tree->right ? 1 + t_height(tree->right) : 0;
	return (left > right ? left : right);
}
