#include "binary_trees.h"


/**
 *binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *@first: Pointer to the first node
 *@second: Pointer to the second node
 *Return: Pointer to the lowest ancestor of the two nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	int first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = depth(first);
	second_depth = depth(second);

	while (first_depth != second_depth)
	{
		if (first_depth > second_depth)
		{
			first = first->parent;
			first_depth--;
		}
		if (second_depth > first_depth)
		{
			second = second->parent;
			second_depth--;
		}
	}

	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}


/**
 *depth - finds the depth of a node to the root node
 *@tree: Pointer to the node
 *Return: depth of the node to the root node
 */
int depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + depth(tree->parent));
}
