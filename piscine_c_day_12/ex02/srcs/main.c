/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:36 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/25 23:41:43 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int		ft_is_error(int error, char *file_name)
{
	if (error == ENOENT || error == ENOTDIR)
	{
		ft_putstr("tail: ");
		ft_putstr(file_name);
		ft_putstr(error == ENOENT ? ": No such file or directory\n"
			: ": Not a directory\n");
		return (1);
	}
	return (0);
}

int		*calculate_totals(int file_descriptor)
{
	int		bytes_read;
	char	prev;
	char	c[1];
	int		*result;

	result = (int*)malloc(sizeof(int) * 2);
	result[0] = 0;
	result[1] = 0;
	bytes_read = read(file_descriptor, c, 1);
	while (bytes_read)
	{
		if (errno == EISDIR)
			return (0);
		prev = c[0];
		result[0]++;
		if (c[0] == '\n')
		{
			result[1]++;
		}
		bytes_read = read(file_descriptor, c, 1);
	}
	result[1]++;
	if (prev == '\n' && c[0] == '\n')
		result[1]--;
	return (result);
}

int		ft_read_file(char *file_name, int flag_amount, int *totals)
{
	int		bytes_read;
	int		counters[2];
	int		file_descriptor;
	char	c[1];

	counters[0] = 0;
	counters[1] = 0;
	file_descriptor = open(file_name, O_RDONLY, S_IRUSR);
	while ((bytes_read = read(file_descriptor, c, 1)))
	{
		if (flag_amount > -1 ? counters[0] >= totals[0] - flag_amount
			: counters[1] >= totals[1] - 10)
			ft_putchar(c[0]);
		counters[0]++;
		if (c[0] == '\n')
			counters[1]++;
	}
	if (close(file_descriptor) == -1)
		return (1);
	return (0);
}

int		ft_read_files(int tot, char **files, int flag_amount)
{
	int		*totals;
	int		file_descriptor;
	int		file;

	file = 0;
	while (file < tot)
	{
		if (tot > 1)
		{
			ft_putstr(file == 0 ? "==> " : "\n==> ");
			ft_putstr(files[file]);
			ft_putstr(" <==\n");
		}
		file_descriptor = open(files[file], O_RDONLY, S_IRUSR);
		if (ft_is_error(errno, files[file]) == 0)
		{
			totals = calculate_totals(file_descriptor);
			if (close(file_descriptor) == -1 ||
				(totals != 0 && ft_read_file(files[file], flag_amount, totals)))
				return (1);
		}
		errno = 0;
		file++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	c;
	int		i;
	int		flag_amount;
	char	**files;

	flag_amount = -1;
	i = -1;
	if (argc == 1)
	{
		while ((c = read(STDIN_FILENO, &c, 1)))
		{
		}
		return (0);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
	{
		flag_amount = ABS(ft_atoi(argv[2]));
		files = (char**)malloc(sizeof(char*) * (argc - 3));
	}
	else
		files = (char**)malloc(sizeof(char*) * (argc - 1));
	while (++i < (flag_amount > -1 ? argc - 3 : argc - 1))
		files[i] = argv[(flag_amount > -1 ? i + 3 : i + 1)];
	return (ft_read_files(flag_amount > -1 ? argc - 3 : argc - 1,
		files, flag_amount));
}
