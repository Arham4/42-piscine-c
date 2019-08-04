/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 01:30:39 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 04:03:48 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			if (str[i] - 'a' < 10)
				str[i] += 16;
			else
				str[i] -= 10;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			if (str[i] - 'A' < 10)
				str[i] += 16;
			else
				str[i] -= 10;
		i++;
	}
	return (str);
}