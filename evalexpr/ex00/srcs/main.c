/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:30:27 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/27 18:53:34 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);
int		eval_expr(char *str);
void	ft_putchar(char c);
char	**ft_split_whitespaces(char *str);

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
