/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:23:41 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/25 21:35:10 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
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
