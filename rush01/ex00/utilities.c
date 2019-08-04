/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 02:15:57 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/21 22:58:51 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putrow(char *row)
{
	int col;

	col = 0;
	while (col < 8)
	{
		ft_putchar(row[col]);
		ft_putchar(' ');
		col++;
	}
	ft_putchar(row[col]);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		is_appropriate_number_count(char *row)
{
	int		col;
	char	*occurrences;
	int		counter;

	occurrences = (char *)malloc(sizeof(char) * 9);
	counter = -1;
	while (++counter < 9)
		occurrences[counter] = 0;
	col = -1;
	while (++col < 9)
		if (row[col] >= '0' && row[col] <= '9')
			occurrences[row[col] - '0'] += 1;
	counter = -1;
	while (++counter < 9)
		if (occurrences[counter] > 1)
			return (0);
	return (1);
}

int		is_valid_input(char grid[9][9])
{
	int		row;
	int		col;
	int		total_length;
	int		total_number;

	total_number = 0;
	total_length = 0;
	row = -1;
	while (++row < 9)
	{
		if (!is_appropriate_number_count(grid[row]))
			return (0);
		col = -1;
		while (++col < 9)
		{
			if ((grid[row][col] < '0' && grid[row][col] != '.')
				|| grid[row][col] > '9')
				return (0);
			else if ((grid[row][col] >= '0' && grid[row][col] <= '9'))
				total_number++;
		}
		total_length += col;
	}
	return (total_number >= 17 && total_length == 81);
}
