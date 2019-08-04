/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:34:28 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 11:26:10 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int v;
	unsigned int c;

	v = value;
	c = 0;
	while (v)
	{
		v &= v - 1;
		c++;
	}
	return (c);
}
