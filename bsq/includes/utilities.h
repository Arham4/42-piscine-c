/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:37:20 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 21:55:11 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MIN3(a, b, c) (MIN(MIN((a), (b)), (c)))
# define CHAR_VALUE(a, b) (a == b[0] ? 1 : 0)

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		str_contains(char c, char *chars, int length);
#endif
