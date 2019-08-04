/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:43:59 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 12:54:36 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int j;
	int count;

	i = 0;
	while (i < length)
	{
		j = 0;
		count = 1;
		while (j < length)
		{
			if (tab[j] == tab[i] && j != i)
			{
				count++;
			}
			j++;
		}
		if (count != 2)
		{
			return (tab[i]);
		}
		i++;
	}
	return (-1);
}
