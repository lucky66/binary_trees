#include "binary_trees.h"
#include <stddef.h>

/**
 *array_to_bst - builds a Binary Search Tree from an array.
 *@array: Pointer to the array to build from.
 *@size: Size of  the array.
 *Return: Pointer to the root node of the tree.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 1;
	bst_t *root = NULL;

	if (!array || size <= 0)
		return (NULL);
	root = bst_insert(&root, array[0]);
	while (i < size)
		bst_insert(&root, array[i++]);
	return (root);
}
