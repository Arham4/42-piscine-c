/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 00:45:38 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 00:55:56 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base != 1)
	{
		if (base % 2 == 0)
		{
			return (1 + ft_collatz_conjecture(base / 2));
		}
		else
		{
			return (1 + ft_collatz_conjecture(base * 3 + 1));
		}
	}
	return (0);
}
