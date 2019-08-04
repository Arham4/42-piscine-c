/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 15:00:58 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/28 18:09:20 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

char	*get_rush_string(int rush, int colle)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (colle ? 12 : 11));
	str[0] = '[';
	str[1] = colle ? 'c' : 'r';
	str[2] = colle ? 'o' : 'u';
	str[3] = colle ? 'l' : 's';
	str[4] = colle ? 'l' : 'h';
	str[5] = colle ? 'e' : '-';
	str[6] = colle ? '-' : '0';
	str[7] = colle ? '0' : rush + '0';
	str[8] = colle ? rush + '0' : ']';
	str[9] = colle ? ']' : ' ';
	str[10] = colle ? ' ' : '\0';
	if (colle)
	{
		str[11] = '\0';
	}
	return (str);
}
