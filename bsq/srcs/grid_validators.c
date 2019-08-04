/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_validators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:48:54 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 23:26:24 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utilities.h>

int		is_valid_grid(char *grid, int *dimensions, char *characters)
{
	int	height;
	int	width;

	height = 0;
	while (height < dimensions[1])
	{
		if (grid[height] == 0)
			return (0);
		width = -1;
		while (++width < dimensions[0])
		{
			if (!str_contains(grid[dimensions[0] * height
				+ height + width], characters, 2))
				break ;
		}
		if (width != dimensions[0])
			return (0);
		height++;
	}
	return (1);
}
