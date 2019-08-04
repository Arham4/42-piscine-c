/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:51:40 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 17:52:01 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *current;
	t_list *temp;

	temp = 0;
	current = begin_list[0];
	while (current)
	{
		temp = current;
		free(current);
		current = temp->next;
	}
	*begin_list = 0;
}
