/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:37:42 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/11 20:18:12 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		index;
	int		index2;
	char	temp;

	index = 0;
	index2 = 0;
	temp = str[0];
	while (str[index] != '\0')
	{
		index++;
	}
	index--;
	while (index >= index2)
	{
		temp = str[index];
		str[index] = str[index2];
		str[index2] = temp;
		index--;
		index2++;
	}
	return (str);
}
