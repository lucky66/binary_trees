#include "binary_trees.h"

/**
 *binary_tree_is_complete - checks if a binary tree is complete.
 *@tree:pointer to the tree to check.
 *Return: 0 or 1
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int null_flag = 0, front = 0, rear = 0;
	binary_tree_t *queue[1000], *tmp;

	if (!tree)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		tmp = queue[front++];
		if (!tmp)
			null_flag = 1;
		else
		{
			if (null_flag)
				return (0);
			queue[rear++] = tmp->left;
			queue[rear++] = tmp->right;
		}
	}
	return (1);
}
