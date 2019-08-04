/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:44:35 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/22 16:44:36 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_ascii_table(char **tab, int size)
{
	int		index;
	int		index2;
	int		str_index;
	int		min_index;
	char	*temp;

	index = 0;
	while (index < size - 1)
	{
		min_index = index;
		index2 = index + 1;
		while (index2 < size)
		{
			str_index = 0;
			while (tab[index2][str_index] == tab[min_index][str_index])
				str_index++;
			if (tab[index2][str_index] < tab[min_index][str_index])
				min_index = index2;
			index2++;
		}
		temp = tab[min_index];
		tab[min_index] = tab[index];
		tab[index] = temp;
		index++;
	}
}

void	ft_sort_wordtab(char **tab)
{
	int size;

	size = 0;
	while (tab[size])
	{
		size++;
	}
	ft_sort_ascii_table(tab, size);
}
