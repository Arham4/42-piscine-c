#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

t_btree *btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (node)
	{
		node->item = item;
		node->left = 0;
		node->right = 0;
		return (node);
	}
	return (0);
}

int cmpf(void *data1, void *data2)
{
	if (data1 < data2)
	{
		return (-1);
	}
	else if (data1 > data2)
	{
		return (1);
	}
	return (0);
}

void applyf(void *data)
{
	printf("%d\n", (int) data);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	applyf(root->item);
	if (root->left)
		btree_apply_prefix(root->left, applyf);
	if (root->right)
		btree_apply_prefix(root->right, applyf);
}

int	main(void)
{
	t_btree	*root;

	root = btree_create_node(8);
	root->left = btree_create_node(4);
	root->left->left = btree_create_node(2);
	root->left->right = btree_create_node(5);
	root->right = btree_create_node(12);
	root->right->right = btree_create_node(14);
	btree_insert_data(&root, 1, cmpf);
	btree_apply_prefix(root, applyf);
}