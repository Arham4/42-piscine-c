/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 21:09:57 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/27 19:26:49 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	operate(int j, int *i, char *str, char **word_array)
{
	int l;

	l = 0;
	while (str[*i + l] != '\t' && str[*i + l] != ' '
		&& str[*i + l] != '\n' && str[*i + l] != '\0'
		&& str[*i + l] != ')')
		l++;
	word_array[j] = (char*)malloc(sizeof(char) * (l + 1));
	l = 0;
	while (str[*i] != '\t' && str[*i] != ' '
		&& str[*i] != '\n' && str[*i] != ')'
		&& str[*i] != '\0')
	{
		word_array[j][l] = str[*i];
		*i = *i + 1;
		l++;
	}
	word_array[j][l] = '\0';
}

int		get_count(char *str)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(' || str[i] == ')')
			words++;
		else if (str[i] != '\t' && str[i] != ' '
			&& str[i] != '\n')
		{
			words++;
			while (str[i] != '\t' && str[i] != ' '
				&& str[i] != '\n' && str[i] != '\0'
				&& str[i] != ')')
				i++;
			i--;
		}
		i++;
	}
	return (words);
}

char	**ft_split_whitespaces(char *str)
{
	char	**word_array;
	int		words;
	int		i;
	int		word;

	words = get_count(str);
	word_array = (char**)malloc(sizeof(char*) * (words + 1));
	i = 0;
	word = 0;
	while (word < words)
		if (str[i] == '(' || str[i] == ')')
		{
			word_array[word] = malloc(sizeof(char) * 2);
			word_array[word][0] = str[i];
			word_array[word][1] = '\0';
			word++;
			i++;
		}
		else if (str[i] != '\t' && str[i] != ' '
			&& str[i] != '\n')
			operate(word++, &(i), str, word_array);
		else
			i++;
	word_array[word] = 0;
	return (word_array);
}
