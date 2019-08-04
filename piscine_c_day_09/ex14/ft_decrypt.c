/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:43:24 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 09:14:03 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
#include <stdlib.h>

int			ft_atoi(char *str)
{
	int index;
	int length;
	int result;
	int pow;

	length = 0;
	result = 0;
	pow = 1;
	while (str[length] != '\0')
		length++;
	index = 0;
	while (++index < length)
		pow *= 10;
	index = -1;
	while (++index < length)
	{
		result += (str[index] - 48) * pow;
		pow /= 10;
	}
	return (result);
}

int			count_persons(char *str)
{
	int i;
	int persons;

	i = 0;
	persons = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ';')
		{
			persons++;
		}
		i++;
	}
	persons++;
	return (persons);
}

void		dummy(t_perso **person, int cs, int c[cs], char *str)
{
	char	*res;

	*person = malloc(sizeof(t_perso));
	res = malloc(sizeof(char) * (c[0] - c[1]));
	c[2] = 0;
	while (c[1] < c[0])
		res[c[2]++] = str[c[1]++];
	(*person)->age = atoi(res);
	c[0]++;
	while (str[c[0]] != ';' && str[c[0]] != 0)
		c[0]++;
}

t_perso		**ft_decrypt(char *str)
{
	t_perso	**result;
	int		c[4];
	int		j;
	t_perso	*person;

	result = malloc(sizeof(t_perso*) * count_persons(str));
	c[0] = 0;
	c[1] = 0;
	c[3] = 0;
	while (str[c[0]++] != '\0')
		if (str[c[0]] == '|')
		{
			dummy(&person, sizeof(c), c, str);
			person->name = malloc(sizeof(char) * (c[0] - c[1]));
			c[0] = c[1] + 1;
			c[2] = 0;
			while (str[c[0]] != ';' && str[c[0]] != 0)
				person->name[c[2]++] = str[c[0]++];
			c[1] = c[0] + 1;
			result[c[3]] = person;
			c[3]++;
		}
	return (result);
}
