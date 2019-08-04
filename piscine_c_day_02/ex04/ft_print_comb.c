/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:05:02 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/11 18:03:28 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb(void)
{
	char number[3];

	number[0] = '0' - 1;
	while (++number[0] <= '7')
	{
		number[1] = number[0];
		while (++number[1] <= '8')
		{
			number[2] = number[1];
			while (++number[2] <= '9')
			{
				ft_putchar(number[0]);
				ft_putchar(number[1]);
				ft_putchar(number[2]);
				if (number[0] != '7' || number[1] != '8' || number[2] != '9')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
