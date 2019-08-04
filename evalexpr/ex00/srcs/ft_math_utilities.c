/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 14:49:48 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/27 19:41:12 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		precedence_value(char op)
{
	if (op == '+' || op == '-')
		return (0);
	if (op == '*' || op == '/' || op == '%')
		return (2);
	if (op == '(' || op == ')')
		return (3);
	return (-1);
}

int		compare_precedence(char op1, char op2)
{
	int op1p;
	int op2p;

	op1p = precedence_value(op1);
	op2p = precedence_value(op2);
	if (op1p > op2p)
		return (1);
	else if (op1p < op2p)
		return (-1);
	return (0);
}

int		do_op(int a, int b, char operation)
{
	if (operation == '+')
		return (a + b);
	else if (operation == '-')
		return (a - b);
	else if (operation == '*')
		return (a * b);
	else if (operation == '/')
		return (a / b);
	return (a % b);
}
