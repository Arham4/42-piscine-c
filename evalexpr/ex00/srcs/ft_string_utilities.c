/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:30:16 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/27 15:30:17 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

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
