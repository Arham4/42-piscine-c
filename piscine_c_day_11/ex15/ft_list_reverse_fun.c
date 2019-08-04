/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:36:45 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 23:37:23 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*temp;

	prev = 0;
	current = begin_list;
	while (current)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	begin_list = prev;
}

