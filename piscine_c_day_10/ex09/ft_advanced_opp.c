/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_opp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:58:23 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 18:59:59 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_advanced_opp.h"
#include "ft_opp.h"

void	do_op(int num1, char *operator, int num2)
{
	int i;

	if (operator[0] == '/' && num2 == 0)
	{
		error("Stop : division by zero");
		return ;
	}
	else if (operator[0] == '%' && num2 == 0)
	{
		error("Stop : modulo by zero");
		return ;
	}
	i = 0;
	while (i < 5)
	{
		if (g_opptab[i].op[0] == operator[0])
		{
			ft_putnbr(g_opptab[i].func(num1, num2));
			break ;
		}
		i++;
	}
	if (i == 5)
		g_opptab[5].func(num1, num2);
}

int		main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	*operator;

	if (argc == 4)
	{
		num1 = ft_atoi(argv[1]);
		operator = argv[2];
		if (ft_strlen(argv[2]) != 1)
			operator = "";
		num2 = ft_atoi(argv[3]);
		do_op(num1, operator, num2);
	}
	return (0);
}
