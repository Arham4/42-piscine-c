/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:28:49 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/12 23:53:33 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int index;
	int index2;
	int min_index;
	int temp;

	index = 0;
	while (index < size - 1)
	{
		min_index = index;
		index2 = index + 1;
		while (index2 < size)
		{
			if (tab[index2] < tab[min_index])
			{
				min_index = index2;
			}
			index2++;
		}
		temp = tab[min_index];
		tab[min_index] = tab[index];
		tab[index] = temp;
		index++;
	}
}
