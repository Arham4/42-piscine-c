/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:45:11 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 20:30:21 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*temp;

	prev = 0;
	current = *begin_list;
	while (current)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	*begin_list = prev;
}
