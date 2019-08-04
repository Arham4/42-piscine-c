/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:02:09 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 17:47:25 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *current;

	if (begin_list[0])
	{
		current = begin_list[0];
		while (current->next)
		{
			current = current->next;
		}
		current->next = ft_create_elem(data);
	}
	else
	{
		begin_list[0] = ft_create_elem(data);
	}
}
