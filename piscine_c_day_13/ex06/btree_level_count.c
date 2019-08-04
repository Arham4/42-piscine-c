/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 04:04:24 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/26 04:45:16 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count_recur(t_btree *root, int level)
{
	int left;
	int right;

	if (!root)
		return (level - 1);
	left = btree_level_count_recur(root->left, level + 1);
	right = btree_level_count_recur(root->right, level + 1);
	return (left > right ? left : right);
}

int		btree_level_count(t_btree *root)
{
	return (btree_level_count_recur(root, 1));
}
