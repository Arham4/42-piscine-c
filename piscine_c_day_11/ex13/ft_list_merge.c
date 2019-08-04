/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:33:06 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 21:35:03 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *current;

	if (begin_list1[0])
	{
		current = begin_list1[0];
		while (current->next)
		{
			current = current->next;
		}
		current->next = begin_list2;
	}
	else
	{
		begin_list1[0] = begin_list2;
	}
}
