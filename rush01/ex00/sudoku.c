/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 02:16:12 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 20:33:29 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	g_grid[9][9];
char	g_winning_board[9][9];
int		g_printed;

void	ft_putchar(char c);
void	ft_putrow(char *row);
void	ft_putstr(char *str);
int		is_valid_input(char grid[9][9]);

void	put_grid(char **raw_input)
{
	int row;
	int col;

	row = 1;
	while (row < 10)
	{
		col = 0;
		while (col < 9)
		{
			g_grid[row - 1][col] = raw_input[row][col];
			col++;
		}
		row++;
	}
}

int		is_viable_number(int number, int row, int col)
{
	int perpendicular_dimension;
	int sectional_row;
	int sectional_col;

	perpendicular_dimension = -1;
	while (++perpendicular_dimension < 9)
		if (g_grid[row][perpendicular_dimension] == (number + '0')
			|| g_grid[perpendicular_dimension][col] == (number + '0'))
			return (0);
	sectional_row = row - (row % 3);
	while (sectional_row < (row - (row % 3) + 3))
	{
		sectional_col = col - (col % 3);
		while (sectional_col < (col - (col % 3) + 3))
		{
			if (g_grid[sectional_row][sectional_col] == (number + '0'))
				return (0);
			sectional_col++;
		}
		sectional_row++;
	}
	return (1);
}

int		print_grid(int force)
{
	int row;
	int col;

	g_printed++;
	if (!force)
	{
		row = -1;
		while (++row < 9)
		{
			col = -1;
			while (++col < 9)
				winning_board[row][col] = g_grid[row][col];
		}
	}
	else
	{
		row = 0;
		while (row < 9)
		{
			ft_putrow(winning_board[row]);
			ft_putchar('\n');
			row++;
		}
	}
	return (1);
}

int		solve_cell(int row, int col)
{
	int	number;
	int viable;

	if (row >= 9)
		return (print_grid(0));
	if (g_grid[row][col] == '.')
	{
		number = 0;
		while (++number < 10)
		{
			viable = is_viable_number(number, row, col);
			if (viable)
			{
				g_grid[row][col] = number + '0';
				if (col + 1 > 8 && solve_cell(row + 1, 0))
					return (1);
				else if (solve_cell(row, col + 1))
					return (1);
				g_grid[row][col] = '.';
			}
		}
		return (0);
	}
	return (solve_cell(col + 1 > 8 ? row + 1 : row, col + 1 > 8 ? 0 : col + 1));
}

int		main(int argc, char **argv)
{
	if (argc == 10)
	{
		put_grid(argv);
		if (!is_valid_input(g_grid))
		{
			ft_putstr("Error\n");
		}
		else
		{
			solve_cell(0, 0);
			if (g_printed != 1)
				ft_putstr("Error\n");
			else
				print_grid(1);
			return (0);
		}
	}
	else
		ft_putstr("Error\n");
	return (1);
}
