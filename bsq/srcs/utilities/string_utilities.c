/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:37:04 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 01:58:19 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		str_contains(char c, char *chars, int length)
{
	int i;

	i = 0;
	while (*chars && i < length)
	{
		if (*chars == c)
			return (1);
		i++;
		chars++;
	}
	return (0);
}
