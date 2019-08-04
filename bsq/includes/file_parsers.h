/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:00:18 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/31 22:50:16 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_PARSERS_H
# define FILE_PARSERS_H

int		get_width(int file_descriptor);
int		parse_height(char *characters, int file_descriptor, char *file_name);
char	*parse_characters(char *characters, int file_descriptor);
char	*parse_grid(int file_descriptor, int total_width, int total_height);
#endif
