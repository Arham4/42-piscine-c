/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 11:24:29 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/13 12:58:03 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime_recursive(int nb, int index)
{
	if (nb % index == 0 || (nb > 2 && nb % 2 == 0) || nb < 2)
	{
		return (0);
	}
	else if (index * index > nb)
	{
		return (1);
	}
	return (ft_is_prime_recursive(nb, index + 1));
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
	{
		return (2);
	}
	else if (ft_is_prime_recursive(nb, 2) == 1)
	{
		return (nb);
	}
	return (ft_find_next_prime(nb + 1));
}
