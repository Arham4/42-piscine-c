/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:00:42 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/28 19:24:36 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	**get_grid_0(int x, int y);
char	**get_grid_1(int x, int y);
char	**get_grid_2(int x, int y);
char	**get_grid_3(int x, int y);
char	**get_grid_4(int x, int y);
char	*get_rush_string(int rush, int colle);

int		is_possible(char **compare_grid, char **output, int *dimensions)
{
	int row;
	int col;

	row = 0;
	while (row < dimensions[1])
	{
		col = 0;
		while (col < dimensions[0])
		{
			if (compare_grid[row][col] != output[row][col])
			{
				return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int		get_possibility(int rush, char **output, int *dimensions)
{
	if (dimensions[0] <= 0 || dimensions[1] <= 0)
		return (1);
	if (rush == 0)
		return (is_possible(get_grid_0(dimensions[0], dimensions[1]),
			output, dimensions));
	else if (rush == 1)
		return (is_possible(get_grid_1(dimensions[0], dimensions[1]),
			output, dimensions));
	else if (rush == 2)
		return (is_possible(get_grid_2(dimensions[0], dimensions[1]),
			output, dimensions));
	else if (rush == 3)
		return (is_possible(get_grid_3(dimensions[0], dimensions[1]),
			output, dimensions));
	else if (rush == 4)
	{
		return (is_possible(get_grid_4(dimensions[0], dimensions[1]),
			output, dimensions));
	}
	return (0);
}

void	print_possibilities(char *possibilities[5], int *dimensions)
{
	int i;
	int outputted;

	i = 0;
	outputted = 0;
	while (i < 5)
	{
		if (possibilities[i] != 0)
		{
			if (outputted > 0)
				ft_putstr(" || ");
			outputted++;
			ft_putstr(possibilities[i]);
			ft_putchar('[');
			ft_putnbr(dimensions[0]);
			ft_putstr("] [");
			ft_putnbr(dimensions[1]);
			ft_putchar(']');
		}
		i++;
	}
	if (outputted == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
}

char	**get_possibilities(char **output, int *dimensions)
{
	int		possibilities[5];
	int		total_possibilities;
	int		i;
	char	**str_res;

	i = -1;
	while (++i < 5)
		possibilities[i] = get_possibility(i, output, dimensions);
	total_possibilities = possibilities[0] + possibilities[1] +
		possibilities[2] + possibilities[3] + possibilities[4];
	i = -1;
	str_res = (char**)malloc(sizeof(char*) * 5);
	while (++i < 5)
	{
		if (possibilities[i] == 1)
			str_res[i] = get_rush_string(i, total_possibilities > 1);
		else
			str_res[i] = 0;
	}
	return (str_res);
}
