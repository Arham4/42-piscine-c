/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_opp.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:47:17 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/23 19:01:47 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADVANCED_OPP_H
# define FT_ADVANCED_OPP_H
# include <unistd.h>

typedef struct	s_opp
{
	char		*op;
	int			(*func)(int, int);
}				t_opp;

int				error(char *message);
int				ft_strlen(char *str);
void			ft_putnbr(int nb);
void			ft_nbr(int nb);
void			ft_putchar(char c);
int				ft_atoi(char *str);
void			do_op(int num1, char *operator, int num2);
int				ft_sub(int num1, int num2);
int				ft_add(int num1, int num2);
int				ft_mul(int num1, int num2);
int				ft_div(int num1, int num2);
int				ft_mod(int num1, int num2);
int				ft_usage(int num1, int num2);

#endif
