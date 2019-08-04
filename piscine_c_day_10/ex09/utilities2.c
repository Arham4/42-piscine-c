/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:59:45 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 18:49:59 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_advanced_opp.h"

int		ft_usage(int num1, int num2)
{
	(void)num1;
	(void)num2;
	error("error : only [ + - * / % ] are accepted.");
	return (0);
}

void	ft_putnbr(int nbr)
{
	ft_nbr(nbr);
	write(1, "\n", 1);
}

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int		error(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	return (0);
}
