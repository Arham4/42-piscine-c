/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:39:03 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 22:59:08 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;

	current = begin_list;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			return (current);
		}
		current = current->next;
	}
	return (0);
}
