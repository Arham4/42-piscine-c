/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:58:01 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 21:58:01 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <utilities.h>

int		*set_up_sum_matrix(char *grid, int *dimensions,
	char *characters)
{
	int		*sum_matrix;
	int		width;
	int		height;

	sum_matrix = malloc(sizeof(int) *
		(dimensions[1] * dimensions[0]));
	height = 0;
	while (height < dimensions[1])
	{
		sum_matrix[dimensions[0] * height] =
			CHAR_VALUE(grid[dimensions[0] * height + height], characters);
		height++;
	}
	width = 0;
	while (width < dimensions[0])
	{
		sum_matrix[width] = CHAR_VALUE(grid[width], characters);
		width++;
	}
	return (sum_matrix);
}

int		*get_sum_matrix(char *grid, int *dimensions, char *characters)
{
	int		*sum_matrix;
	int		width;
	int		height;

	sum_matrix = set_up_sum_matrix(grid, dimensions, characters);
	height = 1;
	while (height < dimensions[1])
	{
		width = 0;
		while (++width < dimensions[0])
			if (CHAR_VALUE(grid[dimensions[0] *
				height + height + width], characters) == 1)
				sum_matrix[dimensions[0] * height + width] =
					MIN3(sum_matrix[dimensions[0] * height + (width - 1)],
					sum_matrix[dimensions[0] * (height - 1) + width],
					sum_matrix[dimensions[0] * (height - 1) + (width - 1)]) + 1;
			else
				sum_matrix[dimensions[0] * height + width] = 0;
		height++;
	}
	return (sum_matrix);
}

int		*get_maximum_entry(int *sum_matrix, int *dimensions)
{
	int		coords[2];
	int		*result;
	int		width;
	int		height;

	coords[0] = 0;
	coords[1] = 0;
	height = -1;
	while (++height < dimensions[1])
	{
		width = -1;
		while (++width < dimensions[0])
			if (sum_matrix[dimensions[0] * height + width]
				> sum_matrix[dimensions[0] * coords[1] + coords[0]])
			{
				coords[0] = width;
				coords[1] = height;
			}
	}
	result = malloc(sizeof(int) * 3);
	result[2] = sum_matrix[dimensions[0] * coords[1] + coords[0]];
	result[0] = coords[0] - result[2];
	result[1] = coords[1] - result[2];
	return (result);
}

void	place_x_in_grid(char *grid, int *maximum_entry, int *dimensions,
	char full_character)
{
	int width;
	int height;

	height = maximum_entry[1] + 1;
	while (height <= maximum_entry[1] + maximum_entry[2])
	{
		width = maximum_entry[0] + 1;
		while (width <= maximum_entry[0] + maximum_entry[2])
		{
			grid[dimensions[0] * height +
				height + width] = full_character;
			width++;
		}
		height++;
	}
}

void	solve_grid_and_print(char *grid, int *dimensions,
	char *characters)
{
	int		*sum_matrix;
	int		*maximum_entry;

	sum_matrix = get_sum_matrix(grid, dimensions, characters);
	maximum_entry = get_maximum_entry(sum_matrix, dimensions);
	place_x_in_grid(grid, maximum_entry, dimensions, characters[2]);
	write(STDOUT_FILENO, grid, dimensions[0] * dimensions[1] + dimensions[1]);
	free(sum_matrix);
	free(maximum_entry);
}
