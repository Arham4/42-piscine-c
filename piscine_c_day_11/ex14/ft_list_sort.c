/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:35:51 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 23:33:00 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*head;
	t_list	*temp;
	t_list	*min;
	t_list	*r;
	void	*data;

	head = *begin_list;
	temp = head;
	while (temp)
	{
		min = temp;
		r = temp->next;
		while (r)
		{
			if (cmp(min->data, r->data) > 0)
			{
				min = r;
			}
			r = r->next;
		}
		data = temp->data;
		temp->data = min->data;
		min->data = data;
		temp = temp->next;
	}
}
