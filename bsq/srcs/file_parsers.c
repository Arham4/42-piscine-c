/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:59:58 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 23:19:45 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utilities.h>

int		get_width(int file_descriptor)
{
	int		magnitude;
	int		bytes_read;
	char	c;

	magnitude = 0;
	while ((bytes_read = read(file_descriptor, &c, 1)))
	{
		magnitude += bytes_read;
		if (c == '\n' || c == '\0' || bytes_read == 0)
		{
			break ;
		}
	}
	return (magnitude - 1);
}

int		parse_height(char *characters, int file_descriptor, char *file_name)
{
	int		number;
	char	temp;
	int		size;
	int		bytes_read;
	int		new_file;

	size = 0;
	new_file = open(file_name, O_RDONLY);
	while ((size += read(new_file, &temp, 1)))
		if (temp == '\n' || temp == '\0')
			break ;
	close(new_file);
	number = 0;
	bytes_read = read(file_descriptor, &temp, 1);
	while (bytes_read < size - 3)
	{
		number = (number * 10) + (temp - '0');
		bytes_read += read(file_descriptor, &temp, 1);
	}
	characters[0] = temp;
	if (bytes_read == 1 && characters[0] == temp)
		return (-1);
	return (number);
}

char	*parse_characters(char *characters, int file_descriptor)
{
	char *o_characters;
	char new_line_ignore;

	o_characters = malloc(sizeof(char) * 2);
	read(file_descriptor, o_characters, 2);
	characters[1] = o_characters[0];
	characters[2] = o_characters[1];
	read(file_descriptor, &new_line_ignore, 1);
	return (characters);
}

char	*parse_grid(int file_descriptor, int total_width, int total_height)
{
	char	*grid;
	int		counters[2];
	char	buffer[total_width];

	while (read(file_descriptor, buffer, 1))
		if (buffer[0] == '\n' || buffer[0] == '\0')
			break ;
	counters[0] = 0;
	grid = malloc((total_width * total_height) + total_height);
	read(file_descriptor, grid, (total_width * total_height) + total_height);
	if (grid[(total_width * total_height) + total_height - 1] != '\n'
		|| read(file_descriptor, buffer, 1) > 0)
		return (0);
	return (grid);
}
