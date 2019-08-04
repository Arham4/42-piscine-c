/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 04:53:36 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/26 06:04:04 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int		*g_levels;
int		btree_level_count(t_btree *root);

void	apply_to_level(t_btree *node, int original_level, int level,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!node)
		return ;
	if (level == 0)
	{
		applyf(node->item, original_level, g_levels[original_level] == 0);
		g_levels[original_level] = 1;
	}
	else if (level > 0)
	{
		apply_to_level(node->left, original_level, level - 1, applyf);
		apply_to_level(node->right, original_level, level - 1, applyf);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem))
{
	int level;
	int	height;

	height = btree_level_count(root);
	g_levels = (int*)malloc(sizeof(int) * height);
	level = 0;
	while (level < height)
	{
		g_levels[level] = 0;
		level++;
	}
	level = 0;
	while (level < height)
	{
		apply_to_level(root, level, level, applyf);
		level++;
	}
}
