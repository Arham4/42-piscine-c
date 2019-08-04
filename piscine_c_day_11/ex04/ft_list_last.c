/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:34:55 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 17:07:29 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *current;

	current = begin_list;
	while (current)
	{
		if (current->next)
		{
			current = current->next;
		}
		else
		{
			break ;
		}
	}
	return (current);
}
