/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 10:31:33 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/13 10:56:24 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime_recursive(int nb, int index)
{
	if (nb % index == 0)
	{
		return (0);
	}
	else if (index * index > nb)
	{
		return (1);
	}
	else
	{
		return (ft_is_prime_recursive(nb, index + 1));
	}
}

int		ft_is_prime(int nb)
{
	if ((nb > 2 && nb % 2 == 0) || nb < 2)
	{
		return (0);
	}
	else
	{
		return (ft_is_prime_recursive(nb, 2));
	}
}
