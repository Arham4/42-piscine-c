/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:33:17 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 22:59:14 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
	*data_ref, int (*cmp)(void *, void *))
{
	t_list *current;

	current = begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			f(current->data);
		}
		current = current->next;
	}
}
