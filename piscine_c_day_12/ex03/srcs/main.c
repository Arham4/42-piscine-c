/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:36 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/25 22:44:44 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int		ft_is_error(int error, char *file_name)
{
	if (error == ENOENT || error == ENOTDIR)
	{
		ft_putstr("hexdump: ");
		ft_putstr(file_name);
		ft_putstr(": No such file or directory\n");
		return (1);
	}
	else if (error == EISDIR)
	{
		ft_putstr("hexdump: ");
		ft_putstr(file_name);
		ft_putstr(": Is a directory\n");
		return (1);
	}
	return (0);
}

void	print_hex(int number)
{
	int result;

	if (number == 0)
	{
		return ;
	}
	result = number % 16;
	print_hex(number / 16);
	if (result >= 10)
	{
		ft_putchar((result % 16 - 10) + 'a');
	}
	else
	{
		ft_putchar((result % 16) + '0');
	}
}

void	print_data(char buffer[17])
{
	int i;

	write(1, "00000000  ", 11);
	while (i < 17)
	{
		print_hex(buffer[i]);
		ft_putchar(' ');
	}
}

int		main(int argc, char **argv)
{
	int		bytes_read;
	char	buffer[17];

	if (argc == 1)
	{
		while ((read(STDIN_FILENO, buffer, 16)))
		{
		}
		return (0);
	}
	bytes_read = read(STDIN_FILENO, buffer, 16);
	while (bytes_read)
	{
		buffer[bytes_read] = '\0';
		print_data(buffer);
	}
	return (0);
}
