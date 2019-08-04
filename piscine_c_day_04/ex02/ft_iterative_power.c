/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:37:54 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/13 13:04:55 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int iterations;
	int result;

	if (power < 0)
	{
		return (0);
	}
	iterations = 0;
	result = 1;
	while (iterations < power)
	{
		result *= nb;
		iterations++;
	}
	return (result);
}
