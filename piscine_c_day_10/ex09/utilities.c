/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:54:05 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 19:01:14 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_advanced_opp.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_nbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_nbr(nb / 10);
		ft_nbr(nb % 10);
	}
}

int		calculate(char *str, int index, int length, int pow)
{
	int result;

	result = 0;
	while (++index < length)
		if (str[index] >= 48 && str[index] <= 57)
		{
			result += (str[index] - 48) * pow;
			pow /= 10;
		}
		else
			break ;
	if (str[0] == '-')
		result *= -1;
	return (result);
}

char	*trim_front(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '+'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r')
	{
		i++;
	}
	str += i;
	return (str);
}

int		ft_atoi(char *str)
{
	int index;
	int length;
	int result;
	int pow;

	str = trim_front(str);
	length = 0;
	result = 0;
	pow = 1;
	while (str[length] != '\0')
		length++;
	index = 0;
	if (str[0] == '-')
		index = 1;
	while (++index < length)
		if (str[index] >= 48 && str[index] <= 57)
			pow *= 10;
		else
			break ;
	index = -1;
	if (str[0] == '-')
		index = 0;
	result = calculate(str, index, length, pow);
	return (result);
}
