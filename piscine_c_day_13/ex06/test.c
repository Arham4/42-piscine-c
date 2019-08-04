#include "ft_btree.h"

int		btree_level_count(t_btree *root);

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

int	main(void)
{
	t_btree	*root;

	root = btree_create_node(8);
	root->left = btree_create_node(4);
	root->left->left = btree_create_node(2);
	root->left->left->left = btree_create_node(15);
	root->left->left->right = btree_create_node(17);
	root->left->left->right->right = btree_create_node(18);
	root->left->right = btree_create_node(5);
	root->right = btree_create_node(12);
	root->right->right = btree_create_node(14);
	printf("%d\n", btree_level_count(root));
}