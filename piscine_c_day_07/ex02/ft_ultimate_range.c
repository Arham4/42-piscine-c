/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:16:52 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/18 18:36:12 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *nums;
	int i;

	if (min >= max)
	{
		*range = (0);
		i = 0;
	}
	else
	{
		nums = (int*)malloc(sizeof(int) * (max - min));
		i = 0;
		while (i < (max - min))
		{
			nums[i] = min + i;
			i++;
		}
		*range = nums;
	}
	return (i);
}
