/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 06:43:23 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 07:17:57 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int		count;
	int		j;
	int		z;

	count = 0;
	z = 0;
	j = 0;
	while (j < length)
	{
		if (tab[j] == 0)
		{
			z = j;
			while (z < length - 1)
			{
				tab[z] = tab[z + 1];
				z++;
			}
		}
		j++;
	}
	while (tab[count] != 0)
	{
		count++;
	}
	return (count);
}
