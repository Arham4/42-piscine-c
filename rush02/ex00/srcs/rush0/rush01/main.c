/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:50:47 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/28 17:01:18 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);
void	rush_1(int x, int y);
void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int x;
	int y;

	if (argc == 3)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (x >= 1 && y >= 1)
		{
			rush_1(x, y);
		}
		else
		{
			ft_putchar('\n');
		}
	}
	else
	{
		ft_putchar('\n');
	}
	return (0);
}
