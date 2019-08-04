/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 12:32:59 by jfrank            #+#    #+#             */
/*   Updated: 2019/07/28 17:01:14 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);

char	**get_grid_3(int x, int y)
{
	char	**grid;
	int		row;
	int		col;

	grid = (char**)malloc(sizeof(char*) * y);
	row = 0;
	while (row < y)
	{
		grid[row] = (char*)malloc(sizeof(char) * x);
		col = -1;
		while (++col < x)
			if ((col == 0 && row == 0) || (col == 0 && row == y - 1))
				grid[row][col] = 'A';
			else if ((col == x - 1 && row == y - 1) ||
				(col == x - 1 && row == 0))
				grid[row][col] = 'C';
			else if (col > 0 && col < x - 1 && (row == 0 || row == y - 1))
				grid[row][col] = 'B';
			else if ((col == 0 || col == x - 1) && (row > 0 && row < y - 1))
				grid[row][col] = 'B';
			else
				grid[row][col] = ' ';
		row++;
	}
	return (grid);
}

void	rush_3(int x, int y)
{
	char	**grid;
	int		row;
	int		col;

	grid = get_grid_3(x, y);
	row = 0;
	while (row < y)
	{
		col = 0;
		while (col < x)
		{
			ft_putchar(grid[row][col]);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
