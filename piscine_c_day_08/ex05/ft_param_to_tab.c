/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 07:38:41 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 23:39:34 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					count_length(char *str)
{
	int length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	copy = (char*)malloc(i * sizeof(char) + 1);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_par	*res;

	res = (struct s_stock_par*)malloc(
		sizeof(struct s_stock_par) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		res[i].size_param = count_length(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		res[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	res[i].str = 0;
	return (res);
}
