/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:41:50 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 22:59:00 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *temp;
	t_list *prev;

	prev = 0;
	temp = 0;
	current = begin_list[0];
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			if (current == begin_list[0])
				begin_list[0] = current->next;
			else
				prev->next = current->next;
			temp = current;
			current = current->next;
			free(temp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
