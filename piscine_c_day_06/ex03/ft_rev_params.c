/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:58:21 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/16 20:15:55 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int i;
	int i2;

	if (argc > 1)
	{
		i = argc - 1;
		while (i >= 1)
		{
			i2 = 0;
			while (argv[i][i2] != '\0')
			{
				ft_putchar(argv[i][i2]);
				i2++;
			}
			i--;
			ft_putchar('\n');
		}
	}
	return (0);
}
