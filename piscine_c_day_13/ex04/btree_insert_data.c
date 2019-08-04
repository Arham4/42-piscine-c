/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:29:49 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/26 06:04:32 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*curr;
	t_btree *prev;

	curr = *root;
	prev = curr;
	while (curr)
	{
		prev = curr;
		if (cmpf(item, curr->item) < 0)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (cmpf(item, prev->item) < 0)
		prev->left = btree_create_node(item);
	else
		prev->right = btree_create_node(item);
}
