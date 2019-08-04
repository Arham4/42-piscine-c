/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:28:32 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 03:29:49 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0L);
	else if (power == 0)
		return (1L);
	return (nb * ft_recursive_power(nb, power - 1));
}

int		*generate_key(int value_for_char, char *base)
{
	int *key;
	int i;

	key = (int*)malloc(sizeof(int) * 128);
	i = 0;
	while (base[i] != '\0')
	{
		if (value_for_char == 1)
			key[(int)base[i]] = i;
		else
			key[i] = base[i];
		i++;
	}
	return (key);
}

long	to_base_10(char *number, int from_base, int *key)
{
	long	result;
	int		i;
	int		pow;

	pow = 0;
	i = 0;
	result = 0;
	while (number[i] != '\0' && number[i] != '.')
		i++;
	i--;
	while (i >= 0)
	{
		if (number[i] != '+')
		{
			result += (key[(int)number[i]]) *
					ft_recursive_power(from_base, pow);
			pow++;
		}
		i--;
	}
	return (result);
}

char	*to_base_n(int neg, long number, int to_base, int *key)
{
	char	*digits;
	long	pows[33];
	int		pow;
	int		digit;

	pow = 0;
	while (pow < 33)
	{
		pows[pow] = ft_recursive_power(to_base, pow);
		if (pows[pow] > number)
			break ;
		pow++;
	}
	digits = (char*)malloc(sizeof(long) * neg ? pow + 1 : pow);
	digit = neg ? 1 : 0;
	digits[0] = neg ? '-' : ' ';
	while (--pow >= 0 && number > 0)
	{
		digits[digit] = key[pows[pow] <= number ? (number / pows[pow]) : 0];
		if (pows[pow] <= number)
			number -= pows[pow] * (number / pows[pow]);
		digit++;
	}
	return (digits);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		bases[2];
	long	number;
	char	*result;
	int		is_neg;

	is_neg = nbr[0] == '-';
	bases[0] = 0;
	bases[1] = 0;
	while (base_from[bases[0]] != '\0')
	{
		bases[0]++;
	}
	while (base_to[bases[1]] != '\0')
	{
		bases[1]++;
	}
	number = to_base_10(nbr, bases[0], generate_key(1, base_from));
	result = to_base_n(is_neg, number, bases[1], generate_key(0, base_to));
	if (number > (is_neg ? 2147483648 : 2147483647) || result[0] == ' ')
		return ("0");
	return (result);
}

int main(void)
{
	printf("%s", ft_convert_base("368754", "0123456789", "01"));
}