/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 02:04:32 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 05:34:34 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		is_not_white_space(char c)
{
	if (c != ' ' && c != '\t'
		&& c != '\n' && c != '+'
		&& c != '\v' && c != '\f'
		&& c != '\r' && c != '\0')
		return (1);
	return (0);
}

char	*trim(char *str)
{
	int i;
	int ideal_index;

	i = 0;
	while (!is_not_white_space(str[i]))
		i++;
	str += i;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_not_white_space(str[i]))
		{
			while (is_not_white_space(str[i]))
				i++;
			ideal_index = i;
		}
		i++;
	}
	str[ideal_index] = '\0';
	return (str);
}

int		same(char *str1, char *str2)
{
	int i;

	i = 0;
	while (ft_str_is_alpha(&(str1[i])) && ft_str_is_alpha(&(str2[i]))
			&& str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i] && str1[i] !=
			(str2[i] >= 'A' && str2[i] <= 'Z' ?
			str2[i] + 32 : str2[i] - 32))
		{
			return (0);
		}
		i++;
	}
	if (str1[i] != '\0' || str2[i] != '\0')
	{
		return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		argv[i] = trim(argv[i]);
		if (same(argv[i], "president") || same(argv[i], "attack")
			|| same(argv[i], "Bauer"))
		{
			write(1, "Alert!!!\n", 9);
			break ;
		}
		i++;
	}
}
