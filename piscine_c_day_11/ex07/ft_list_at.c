/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:27:35 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 19:44:40 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	length;
	t_list			*current;

	length = 0;
	current = begin_list;
	while (current)
	{
		if (length == nbr)
		{
			return (current);
		}
		current = current->next;
		length++;
	}
	return (0);
}
