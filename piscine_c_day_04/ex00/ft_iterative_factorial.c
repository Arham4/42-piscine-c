/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:42:06 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/13 14:10:10 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int fact;

	if (nb < 0)
	{
		fact = 0;
	}
	else
	{
		fact = 1;
		while (nb > 0)
		{
			fact *= nb;
			nb--;
		}
	}
	return (fact);
}
