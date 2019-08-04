/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:43:06 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 19:06:56 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *copy;

	copy = (int*)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		copy[i] = tab[i];
		copy[i] = f(copy[i]);
		i++;
	}
	return (copy);
}
