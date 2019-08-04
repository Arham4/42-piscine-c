/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:26:36 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/25 21:57:59 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int		ft_read_stdout(void);

int		ft_is_error(int error, char *file_name)
{
	if (error == ENOENT || error == ENOTDIR)
	{
		ft_putstr("cat: ");
		ft_putstr(file_name);
		ft_putstr(": No such file or directory\n");
		return (1);
	}
	else if (error == EISDIR)
	{
		ft_putstr("cat: ");
		ft_putstr(file_name);
		ft_putstr(": Is a directory\n");
		return (1);
	}
	return (0);
}

void	ft_read(int input_type, char *file_name)
{
	char	buffer[BUF_SIZE + 1];
	int		bytes_read;

	bytes_read = read(input_type, buffer, BUF_SIZE);
	if (ft_is_error(errno, file_name) == 0)
	{
		while (bytes_read)
		{
			buffer[bytes_read] = '\0';
			ft_putstr(buffer);
			bytes_read = read(input_type, buffer, BUF_SIZE);
		}
	}
}

int		ft_read_files(char **argv)
{
	int		file_descriptor;
	int		file;

	file = 1;
	while (argv[file])
	{
		file_descriptor = open(argv[file], O_RDONLY, S_IRUSR);
		if (argv[file][0] == '-')
			return (ft_read_stdout());
		if (ft_is_error(errno, argv[file]) == 0)
		{
			ft_read(file_descriptor, argv[file]);
			if (close(file_descriptor) == -1)
				return (1);
		}
		errno = 0;
		file++;
	}
	return (0);
}

int		ft_read_stdout(void)
{
	errno = 0;
	ft_read(STDIN_FILENO, "");
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		return (ft_read_stdout());
	}
	return (ft_read_files(argv));
}
