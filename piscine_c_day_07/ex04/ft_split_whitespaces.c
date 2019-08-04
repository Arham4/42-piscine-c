/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:09:57 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/18 14:26:41 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	operate(int j, int *i, char *str, char **word_array)
{
	int l;

	l = 0;
	while (str[*i + l] != '\t' && str[*i + l] != ' '
		&& str[*i + l] != '\n' && str[*i + l] != '\0')
		l++;
	word_array[j] = (char*)malloc(sizeof(char) * (l + 1));
	l = 0;
	while (str[*i] != '\t' && str[*i] != ' '
		&& str[*i] != '\n' && str[*i] != '\0')
	{
		word_array[j][l] = str[*i];
		*i = *i + 1;
		l++;
	}
	word_array[j][l] = '\0';
}

char	**ft_split_whitespaces(char *str)
{
	char	**word_array;
	int		ints[3];

	ints[0] = 0;
	ints[1] = 0;
	while (str[ints[0]] != '\0')
		if (str[ints[0]] != '\t' && str[ints[0]] != ' ' && str[ints[0]] != '\n')
		{
			ints[1]++;
			while (str[ints[0]] != '\t' && str[ints[0]] != ' '
				&& str[ints[0]] != '\n' && str[ints[0]] != '\0')
				ints[0]++;
		}
		else
			ints[0]++;
	word_array = (char**)malloc(sizeof(char*) * (ints[1] + 1));
	ints[0] = 0;
	ints[2] = 0;
	while (ints[2] < ints[1])
		if (str[ints[0]] != '\t' && str[ints[0]] != ' ' && str[ints[0]] != '\n')
			operate(ints[2]++, &(ints[0]), str, word_array);
		else
			ints[0]++;
	word_array[ints[2]] = 0;
	return (word_array);
}
