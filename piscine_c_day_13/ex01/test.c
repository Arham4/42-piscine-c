#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));

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

void applyf(void *data)
{
	printf("%d\n", (int) data);
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
	btree_apply_prefix(root, applyf);
}