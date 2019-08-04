/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:14:28 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 22:55:37 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <utilities.h>
#include <file_parsers.h>
#include <grid_validators.h>
#include <bsq.h>

void	save_stdin_to_file(char *file_name)
{
	int		bytes_read;
	char	buffer[16384 + 1];
	int		file_descriptor;

	file_descriptor = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	while ((bytes_read = read(STDIN_FILENO, buffer, 16384)))
	{
		buffer[bytes_read] = '\0';
		write(file_descriptor, buffer, bytes_read);
	}
	close(file_descriptor);
}

int		finish_process(int file_descriptor, char *grid,
	char *characters, int error)
{
	if (error)
		write(STDERR_FILENO, "map error\n", 10);
	if (file_descriptor >= 0)
		close(file_descriptor);
	if (grid != 0)
		free(grid);
	if (characters != 0)
		free(characters);
	return (0);
}

int		process_file(char *file_name)
{
	int		file_descriptor;
	int		dimensions[2];
	char	*characters;
	char	*grid;

	file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor < 0)
		return (finish_process(-1, 0, 0, 1));
	characters = malloc(sizeof(char) * 3);
	dimensions[1] = parse_height(characters, file_descriptor, file_name);
	if (dimensions[1] <= 0)
		return (finish_process(file_descriptor, 0, characters, 1));
	characters = parse_characters(characters, file_descriptor);
	dimensions[0] = get_width(file_descriptor);
	if (dimensions[0] <= 0)
		return (finish_process(file_descriptor, 0, characters, 1));
	close(file_descriptor);
	file_descriptor = open(file_name, O_RDONLY);
	grid = parse_grid(file_descriptor, dimensions[0], dimensions[1]);
	if (grid != 0 && is_valid_grid(grid, dimensions, characters))
		solve_grid_and_print(grid, dimensions, characters);
	else
		return (finish_process(file_descriptor, grid, characters, 1));
	return (finish_process(file_descriptor, grid, characters, 0));
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		argv = malloc(sizeof(char*) * 2);
		argv[1] = "bsq.txt";
		save_stdin_to_file(argv[1]);
	}
	argv++;
	while (*argv)
	{
		process_file(*argv);
		argv++;
		if (*argv)
			ft_putchar('\n');
	}
	return (0);
}
