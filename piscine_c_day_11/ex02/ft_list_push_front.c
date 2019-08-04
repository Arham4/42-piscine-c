/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:15:18 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 16:31:53 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *begin;

	begin = ft_create_elem(data);
	if (begin)
	{
		if (begin_list[0])
		{
			begin->next = begin_list[0];
		}
		begin_list[0] = begin;
	}
}
