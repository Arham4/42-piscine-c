/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:44:52 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/22 16:44:55 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_ascii_table(char **tab, int size, int (*cmp)(char *, char *))
{
	int		index;
	int		index2;
	int		min_index;
	char	*temp;

	index = 0;
	while (index < size - 1)
	{
		min_index = index;
		index2 = index + 1;
		while (index2 < size)
		{
			if (cmp(tab[index2], tab[min_index]) < 0)
				min_index = index2;
			index2++;
		}
		temp = tab[min_index];
		tab[min_index] = tab[index];
		tab[index] = temp;
		index++;
	}
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int size;

	size = 0;
	while (tab[size])
	{
		size++;
	}
	ft_sort_ascii_table(tab, size, cmp);
}
