/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 15:29:51 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/27 19:47:49 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split_whitespaces(char *str);
int		is_digit(char c);
int		compare_precedence(char op1, char op2);
int		ft_atoi(char *str);
char	*ft_itoa(int nbr);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		do_op(int a, int b, char operation);

char	**g_output_queue;
char	*g_operator_stack;
int		g_q_index;
int		g_o_index;

void	shift_all(char **list, int to_index, int from_index)
{
	int i;

	i = 0;
	while (i < 100 - from_index)
	{
		list[to_index + i] = list[from_index + i];
		i++;
	}
}

int		parse_output_queue(void)
{
	int i;
	int result;
	int number1;
	int number2;

	result = g_output_queue[0] ? ft_atoi(g_output_queue[0]) : 0;
	i = 0;
	while (g_output_queue[i])
	{
		if (!is_digit(g_output_queue[i][0]))
		{
			number1 = ft_atoi(g_output_queue[i - 2]);
			number2 = ft_atoi(g_output_queue[i - 1]);
			result = do_op(number1, number2, g_output_queue[i][0]);
			g_output_queue[i - 2] = ft_itoa(result);
			shift_all(g_output_queue, i - 1, i + 1);
			i -= 2;
		}
		i++;
	}
	return (result);
}

void	handle_operator(char operator)
{
	while (compare_precedence(operator,
		g_operator_stack[g_o_index - 1]) <= 0
		&& g_operator_stack[g_o_index - 1] != '(')
	{
		g_output_queue[g_q_index] = (char*)malloc(sizeof(char));
		g_output_queue[g_q_index++][0] = g_operator_stack[--g_o_index];
	}
	g_operator_stack[g_o_index++] = operator;
}

void	equate_parenthesis(void)
{
	while (g_operator_stack[g_o_index - 1] != '(')
	{
		g_output_queue[g_q_index] = (char*)malloc(sizeof(char));
		g_output_queue[g_q_index++][0] = g_operator_stack[--g_o_index];
	}
	if (g_operator_stack[g_o_index - 1] == '(')
		g_o_index--;
}

int		eval_expr(char *str)
{
	char	**tabs;

	tabs = ft_split_whitespaces(str);
	g_q_index = 0;
	g_o_index = 0;
	g_output_queue = (char**)malloc(sizeof(char*) * 100);
	g_operator_stack = (char*)malloc(sizeof(char) * 100);
	while (*tabs)
	{
		if (is_digit(*tabs[0]))
			g_output_queue[g_q_index++] = *tabs;
		else if (*tabs[0] != '(' && *tabs[0] != ')')
			handle_operator(*tabs[0]);
		else if (*tabs[0] == '(')
			g_operator_stack[g_o_index++] = *tabs[0];
		else if (*tabs[0] == ')')
			equate_parenthesis();
		tabs++;
	}
	while (g_operator_stack && g_o_index > 0)
	{
		g_output_queue[g_q_index] = (char*)malloc(sizeof(char));
		g_output_queue[g_q_index++][0] = g_operator_stack[--g_o_index];
	}
	return (parse_output_queue());
}
