/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 20:24:18 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/17 21:17:17 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*lol(int argc, char **argv, char *res)
{
	int i;
	int j;
	int characters;

	i = 1;
	characters = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			res[characters] = argv[i][j];
			characters++;
			j++;
		}
		if (i != argc - 1)
			res[characters] = '\n';
		characters++;
		i++;
	}
	return (res);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		characters;
	char	*res;

	i = 1;
	characters = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
		}
		characters += j;
		i++;
	}
	res = (char*)malloc(sizeof(char) * characters);
	res = lol(argc, argv, res);
	return (res);
}
