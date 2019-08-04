/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:35:52 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/16 18:56:21 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
