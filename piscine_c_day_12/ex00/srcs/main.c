/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:28:14 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/25 21:28:43 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int		main(int argc, char **argv)
{
	int		file_descriptor;
	int		bytes_read;
	char	buffer[BUF_SIZE + 1];

	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	file_descriptor = open(argv[1], O_RDONLY);
	bytes_read = read(file_descriptor, buffer, BUF_SIZE);
	while (bytes_read)
	{
		buffer[bytes_read] = '\0';
		ft_putstr(buffer);
		bytes_read = read(file_descriptor, buffer, BUF_SIZE);
	}
	if (close(file_descriptor) == -1)
		return (1);
	return (0);
}
