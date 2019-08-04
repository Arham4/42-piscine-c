/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 23:25:36 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 23:32:26 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_STOCK_PAR_H
# define __FT_STOCK_PAR_H
# include <stdlib.h>

typedef struct	s_stock_par {
	int			size_param;
	char		*str;
	char		*copy;
	char		**tab;
}				t_stock_par;
void			ft_putchar(char c);
char			**ft_split_whitespaces(char *str);
void			ft_show_tab(t_stock_par *tab);
#endif
