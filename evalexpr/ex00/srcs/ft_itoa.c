/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:49:10 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/27 19:49:12 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_digits(long number)
{
	long	divisible_check;
	int		digits;

	digits = number == 0 ? 1 : 0;
	divisible_check = 1;
	while (number % divisible_check != number)
	{
		digits++;
		divisible_check *= 10;
	}
	return (digits);
}

char	*ft_itoa_ac(long number)
{
	char	*res;
	int		i;
	int		neg;
	int		digits;

	neg = number < 0 ? 1 : 0;
	number = neg ? number * -1L : number;
	digits = get_digits(number);
	i = digits - 1;
	res = malloc(sizeof(char) * (neg ? (digits + 2) : (digits + 1)));
	res[neg ? (digits + 1) : digits] = '\0';
	if (neg)
	{
		res[0] = '-';
		i++;
	}
	while (i >= (neg ? 1 : 0))
	{
		res[i] = (number % 10) + '0';
		number /= 10;
		i--;
	}
	return (res);
}

char	*ft_itoa(int nbr)
{
	return (ft_itoa_ac(nbr));
}
