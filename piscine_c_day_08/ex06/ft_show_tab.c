/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:25:31 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 23:33:43 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

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

void	ft_putnbr_recursive(int nb)
{
	if (nb < 10 && nb > -10)
	{
		ft_putchar((nb > 0 ? nb : -nb) + '0');
	}
	else
	{
		ft_putnbr_recursive(nb / 10);
		ft_putnbr_recursive(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	ft_putnbr_recursive(nb);
}

void	ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		if (par[i].tab[j] == 0)
			ft_putchar('\n');
		else
		{
			j = 0;
			while (par[i].tab[j])
			{
				ft_putchar('\n');
				ft_putstr(par[i].tab[j]);
				j++;
			}
		}
	}
}
