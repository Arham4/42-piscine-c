/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:37:15 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 17:46:21 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*current;
	t_list	*temp;
	int		i;

	i = 1;
	temp = ft_create_elem(av[0]);
	if (ac > 1)
	{
		while (i < ac)
		{
			current = ft_create_elem(av[i]);
			current->next = temp;
			temp = current;
			i++;
		}
	}
	else
	{
		current = ft_create_elem(av[0]);
	}
	return (current);
}
