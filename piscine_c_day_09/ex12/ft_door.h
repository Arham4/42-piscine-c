/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 05:45:48 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/19 06:33:13 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_DOOR_H
# define __FT_DOOR_H
# define EXIT_SUCCESS 0
# define FALSE 0
# define TRUE 1
# define CLOSE 0
# define OPEN 1

typedef int		t_bool;
typedef struct	s_door {
	t_bool state;
}				t_door;

t_bool			open_door(t_door *door);
t_bool			close_door(t_door *door);
t_bool			is_door_open(t_door *door);
t_bool			is_door_close(t_door *door);

#endif
