/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 05:05:21 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 05:13:59 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PERSO_H
# define __FT_PERSO_H
# include <string.h>
# define SAVE_THE_WORLD "WE OUT HERE"

typedef struct	s_person {
	char	*name;
	float	life;
	int		age;
	char	*profession;
}				t_perso;
#endif
