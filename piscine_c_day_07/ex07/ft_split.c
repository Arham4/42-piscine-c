/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:41:18 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/18 22:18:01 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *g_charset;

int		char_in_set(char character)
{
	int i;

	i = 0;
	while (g_charset[i] != '\0')
	{
		if (g_charset[i] == character)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	operate(int j, int *i, char *str, char **word_array)
{
	int l;

	l = 0;
	while (!char_in_set(str[*i + l]) && str[*i + l] != '\0')
		l++;
	word_array[j] = (char*)malloc(sizeof(char) * (l + 1));
	l = 0;
	while (!char_in_set(str[*i]) && str[*i] != '\0')
	{
		word_array[j][l] = str[*i];
		*i = *i + 1;
		l++;
	}
	word_array[j][l] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**word_array;
	int		ints[3];

	g_charset = charset;
	ints[0] = 0;
	ints[1] = 0;
	while (str[ints[0]] != '\0')
		if (!char_in_set(str[ints[0]]))
		{
			ints[1]++;
			while (!char_in_set(str[ints[0]]) && str[ints[0]] != '\0')
				ints[0]++;
		}
		else
			ints[0]++;
	word_array = (char**)malloc(sizeof(char*) * (ints[1] + 1));
	ints[0] = 0;
	ints[2] = 0;
	while (ints[2] < ints[1])
		if (!char_in_set(str[ints[0]]))
			operate(ints[2]++, &(ints[0]), str, word_array);
		else
			ints[0]++;
	word_array[ints[2]] = 0;
	return (word_array);
}
