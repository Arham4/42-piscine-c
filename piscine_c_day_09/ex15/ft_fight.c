/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:28:27 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 16:28:28 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fight.h"
#include "ft_perso.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &(str[i]), 1);
		i++;
	}
}

int	main(void)
{
	t_perso test;
	t_perso test2;

	ft_fight(&test, &test2, KICK);
	return (0);
}

void	ft_fight(t_perso *attacker, t_perso *victim, int damage)
{
	if (attacker->life < 0 && victim->life < 0)
		return ;
	victim->life -= damage;
	ft_putstr(attacker->name);
	ft_putstr(" does a ");
	if (damage == KICK)
		ft_putstr("judo kick");
	else if (damage == PUNCH)
		ft_putstr("judo punch");
	else
		ft_putstr("judo headbutt");
	ft_putstr(" on ");
	ft_putstr(victim->name);
	ft_putstr(".\n");
	if (victim->life < 0)
	{
		ft_putstr(victim->name);
		ft_putstr(" is dead.\n");
	}
}
