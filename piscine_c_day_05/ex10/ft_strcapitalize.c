/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:41:03 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/15 20:29:37 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_alpha_numeric(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')
		|| (letter >= '0' && letter <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int cap;

	i = 0;
	cap = 1;
	while (str[i] != '\0')
	{
		if (ft_is_alpha_numeric(str[i]) == 0)
			cap = 1;
		else if (cap == 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if (cap == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			cap = 0;
		}
		i++;
	}
	return (str);
}
