#include "binary_trees.h"


/**
 *binary_tree_depth - measures the depth of a node in a binary tree.
 *@tree: treeointr to the tree to measure its depth.
 *Return: Depth of the tree.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (!tree)
		return (0);
	while (tree)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth - 1);
}
