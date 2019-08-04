/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:22:18 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/13 13:05:18 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt_recursive(int nb, int index)
{
	if (index * index > nb)
	{
		return (0);
	}
	else if (index * index == nb)
	{
		return (index);
	}
	else
	{
		return (ft_sqrt_recursive(nb, index + 1));
	}
}

int		ft_sqrt(int nb)
{
	return (ft_sqrt_recursive(nb, 0));
}
