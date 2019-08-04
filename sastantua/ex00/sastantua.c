/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 21:12:16 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/15 00:00:37 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		g_height;
int		g_width;

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return 0;
}

int		get_dimension(int width, int side_inc, int section, int size)
{
	int height;

	if (width == -1)
	{
		height = 2 + section;
		if (section == size)
			return (height);
		return (height + get_dimension(width, side_inc, section + 1, size));
	}
	height = 2 + section;
	while (height > 1)
	{
		width += 2;
		height--;
	}
	if ((section <= 4 && section % 3 == 0) || (section > 4 && section % 2 == 1))
		side_inc += 2;
	if (section == size)
		return (width);
	return (get_dimension(width + side_inc, side_inc, section + 1, size));
}

int		get_max_new_section_cut_off(int size)
{
	int level;
	int new_section_cut_off;

	new_section_cut_off = 3;
	level = 2;
	while (level <= size)
	{
		if ((level <= 4 && level % 3 == 0) || (level > 4 && level % 2 == 1))
		{
			new_section_cut_off += 1;
		}
		level++;
	}
	return (new_section_cut_off);
}

void	add_door(int size, char grid[g_height][g_width])
{
	int d[2];

	if (size <= 2)
		grid[g_height - 1][g_width / 2] = '|';
	else if (size <= 4)
	{
		d[1] = g_height - 4;
		while (++d[1] <= g_height - 1)
		{
			d[0] = g_width / 2 - 2;
			while (++d[0] <= g_width / 2 + 1)
				grid[d[1]][d[0]] = '|';
		}
	}
	else
	{
		d[1] = g_height - size - 1;
		while (++d[1] <= g_height - 1)
		{
			d[0] = g_width / 2 - (size / 2) - 1;
			while (++d[0] <= g_width / 2 + (size / 2))
				grid[d[1]][d[0]] = '|';
		}
		grid[g_height - size / 2 - 1][g_width / 2 + size / 2 - 1] = '$';
	}
}

void	fill_grid(char grid[g_height][g_width], int cs, int count[cs])
{
	while (--count[0] >= 0)
	{
		if (--count[2] == 0 && count[6] != 0)
		{
			if (count[6] <= 4 ? count[6] % 3 == 0 : count[6] % 2 == 1)
				count[3] -= 1;
			count[6]--;
			count[2] = 2 + count[6];
			count[7] += count[3] - 1;
		}
		count[1] = -1;
		while (++count[1] < g_width)
			if (count[1] == count[7])
				grid[count[0]][count[1]] = '/';
			else if (count[1] == g_width - 1 - count[7])
				grid[count[0]][count[1]] = '\\';
			else if (count[1] < count[7] || count[1] > g_width - 1 - count[7])
				grid[count[0]][count[1]] = ' ';
			else
				grid[count[0]][count[1]] = '*';
		count[7]++;
	}
}

void	sastantua(int size)
{
	char	grid[get_dimension(-1, 0, 1, size)][get_dimension(3, 6, 1, size)];
	int		counters[8];

	counters[6] = size;
	g_width = get_dimension(3, 6, 1, counters[6]);
	g_height = get_dimension(-1, 0, 1, counters[6]);
	counters[0] = g_height;
	counters[3] = get_max_new_section_cut_off(counters[6]);
	counters[1] = -1;
	counters[2] = 3 + counters[6];
	counters[7] = 0;
	fill_grid(grid, 8, counters);
	add_door(size % 2 == 0 ? size - 1 : size, grid);
	while (++counters[0] < g_height)
	{
		counters[1] = -1;
		while (++counters[1] < g_width)
		{
			ft_putchar(grid[counters[0]][counters[1]]);
			if (grid[counters[0]][counters[1]] == '\\')
				break ;
		}
		ft_putchar('\n');
	}
}

int		main(void)
{
	sastantua(0);
	return 0;
}
