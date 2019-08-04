/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 03:48:36 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/26 06:04:53 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "stdlib.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*result;

	if (!data_ref || !root)
		return (NULL);
	if (root->left)
	{
		result = btree_search_item(root->left, data_ref, cmpf);
		if (result)
			return (result);
	}
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	if (root->right)
	{
		result = btree_search_item(root->right, data_ref, cmpf);
		if (result)
			return (result);
	}
	return (NULL);
}
