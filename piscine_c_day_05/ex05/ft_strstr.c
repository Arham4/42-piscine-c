/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:02:26 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/16 16:03:27 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		find_i;

	if (to_find[0] == '\0')
		return (&(str[0]));
	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			find_i = 0;
			while (str[++i] != '\0' && to_find[find_i + 1] != '\0')
				if (str[i] != to_find[++find_i])
				{
					find_i = -2;
					break ;
				}
			if (find_i == -2)
				continue ;
			if (to_find[find_i + 1] != '\0')
				return (0);
			return (&str[i - find_i - 1]);
		}
	}
	return (0);
}
