/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 17:45:18 by mlau              #+#    #+#             */
/*   Updated: 2019/07/14 22:43:18 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		rush(int width, int height)
{
	int counter;
	int counter2;

	if (width <= 0 || height <= 0)
		return (0);
	counter2 = -1;
	while (++counter2 < height)
	{
		counter = -1;
		if (counter2 == 0 || counter2 == height - 1)
			while (++counter < width)
				if (counter == 0)
					ft_putchar('A');
				else if (counter == width - 1)
					ft_putchar('C');
				else
					ft_putchar('B');
		else
			while (++counter < width)
				if (counter == 0 || counter == width - 1)
					ft_putchar('B');
				else
					ft_putchar(' ');
		ft_putchar('\n');
	}
	return (0);
}
