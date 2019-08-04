/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 18:34:37 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/16 19:03:16 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

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
