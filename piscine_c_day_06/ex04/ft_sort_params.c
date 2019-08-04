/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:02:20 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/16 20:15:43 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_sort_ascii_table(char *tab[], int size)
{
	int		index;
	int		index2;
	int		str_index;
	int		min_index;
	char	*temp;

	index = 0;
	while (index < size - 1)
	{
		min_index = index;
		index2 = index + 1;
		while (index2 < size)
		{
			str_index = 0;
			while (tab[index2][str_index] == tab[min_index][str_index])
				str_index++;
			if (tab[index2][str_index] < tab[min_index][str_index])
				min_index = index2;
			index2++;
		}
		temp = tab[min_index];
		tab[min_index] = tab[index];
		tab[index] = temp;
		index++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		i2;
	char	*program_name;

	if (argc > 1)
	{
		program_name = argv[0];
		ft_sort_ascii_table(argv, argc);
		i = 0;
		while (i < argc)
		{
			if (argv[i] != program_name)
			{
				i2 = 0;
				while (argv[i][i2] != '\0')
				{
					ft_putchar(argv[i][i2]);
					i2++;
				}
				ft_putchar('\n');
			}
			i++;
		}
	}
	return (0);
}
