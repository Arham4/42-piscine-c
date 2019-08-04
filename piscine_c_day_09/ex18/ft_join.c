/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:49:35 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 13:11:25 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*join(char **tab, int word_cap, int sep_cap, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	j = 0;
	result = (char*)malloc(word_cap);
	k = 0;
	while (k < word_cap - 1)
	{
		j = 0;
		while (tab[i][j])
			result[k++] = tab[i][j++];
		j = 0;
		while (j < sep_cap)
			result[k++] = sep[j++];
		i++;
	}
	return (result);
}

char	*ft_join(char **tab, char *sep)
{
	int		i;
	int		j;
	int		total_characters[2];
	char	*result;
	int		k;

	i = -1;
	total_characters[1] = 0;
	while (sep[++i])
		total_characters[1]++;
	i = -1;
	total_characters[0] = 0;
	while (tab[++i][0] != 0)
	{
		j = 0;
		while (tab[i][j])
			j++;
		total_characters[0] += j + total_characters[1];
	}
	result = join(tab, total_characters[0], total_characters[1], sep);
	result[total_characters[0] - 1] = '\0';
	return (result);
}
