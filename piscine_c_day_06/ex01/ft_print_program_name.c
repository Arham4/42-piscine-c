/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:42:01 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/16 20:15:57 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char *argv[])
{
	char	*name;
	int		i;

	if (argc > 0)
	{
		name = argv[0];
		i = 0;
		while (name[i] != '\0')
		{
			ft_putchar(name[i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
