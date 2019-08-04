/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 21:18:44 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/28 21:54:49 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 30720

void	print_possibilities(char *possibilities[5], int *dimensions);
char	**get_possibilities(char **output, int *dimensions);

int		*get_dimensions(char buffer[BUFFER_SIZE + 1])
{
	int	*dimensions;
	int	finished_width;
	int	i;

	dimensions = (int*)malloc(sizeof(int) * 2);
	dimensions[0] = 0;
	dimensions[1] = 0;
	finished_width = 0;
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			dimensions[1]++;
			finished_width = 1;
		}
		else if (!finished_width)
		{
			dimensions[0]++;
		}
		i++;
	}
	if (dimensions[0] == 0)
		dimensions[1] = 0;
	return (dimensions);
}

char	**get_output(char buffer[BUFFER_SIZE + 1], int *dimensions)
{
	int		w;
	int		h;
	char	**output;

	h = 0;
	output = (char**)malloc(sizeof(char*) * dimensions[1]);
	while (h < dimensions[1])
	{
		w = 0;
		output[h] = (char*)malloc(sizeof(char) * dimensions[0] + 1);
		while (w < dimensions[0])
		{
			output[h][w] = buffer[dimensions[0] * h + h + w];
			w++;
		}
		output[h][w] = '\0';
		h++;
	}
	return (output);
}

int		main(void)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	int		*dimensions;
	char	**output;
	char	**possibilities;

	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	dimensions = get_dimensions(buffer);
	buffer[bytes_read] = '\0';
	output = get_output(buffer, dimensions);
	possibilities = get_possibilities(output, dimensions);
	print_possibilities(possibilities, dimensions);
	return (0);
}
