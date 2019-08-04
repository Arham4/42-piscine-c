/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 23:50:24 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 02:34:36 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	write_next_hour(int hour)
{
	int		next_hour;
	char	*time;

	next_hour = hour + 1;
	time = "A.M.";
	if (next_hour >= 12)
	{
		time = "P.M.";
	}
	if (next_hour == 24)
	{
		next_hour = 12;
		time = "A.M.";
	}
	if (next_hour < 10)
	{
		printf("0%d.00 %s", next_hour, time);
	}
	else
	{
		printf("%d%d.00 %s", next_hour / 10, next_hour % 10, time);
	}
}

void	ft_takes_place(int hour)
{
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	write_next_hour(hour - 1);
	printf(" AND ");
	write_next_hour(hour);
}
