/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:34:43 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 19:02:26 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_nbr(int nb);
int		ft_atoi(char *str);

void	ft_putnbr(int nbr)
{
	ft_nbr(nbr);
	write(1, "\n", 1);
}

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

int		error(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	return (0);
}

void	do_op(int num1, char operator, int num2)
{
	if (operator == '+')
		ft_putnbr(num1 + num2);
	else if (operator == '-')
		ft_putnbr(num1 - num2);
	else if (operator == '/')
	{
		if (num2 == 0)
			error("Stop : division by zero");
		else
			ft_putnbr(num1 / num2);
	}
	else if (operator == '*')
		ft_putnbr(num1 * num2);
	else if (operator == '%')
	{
		if (num2 == 0)
			error("Stop : modulo by zero");
		else
			ft_putnbr(num1 % num2);
	}
	else
		error("0");
}

int		main(int argc, char **argv)
{
	int		num1;
	int		num2;
	char	operator;

	if (argc == 4)
	{
		if (ft_strlen(argv[2]) != 1)
		{
			return (error("0"));
		}
		num1 = ft_atoi(argv[1]);
		operator = argv[2][0];
		num2 = ft_atoi(argv[3]);
		do_op(num1, operator, num2);
	}
	return (0);
}
