/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 03:11:14 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/21 18:16:31 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match_rec(int s1_index, int s2_index, char *s1, char *s2)
{
	if (s1[s1_index] == '\0' && s2[s2_index] == '\0')
		return (1);
	if (s1[s1_index] == '\0' && s2[s2_index] == '*')
		return (match_rec(s1_index, s2_index + 1, s1, s2));
	if (s2[s2_index] == '*')
	{
		return (match_rec(s1_index + 1, s2_index, s1, s2)
			|| match_rec(s1_index, s2_index + 1, s1, s2));
	}
	if (s1[s1_index] == s2[s2_index])
		return (match_rec(s1_index + 1, s2_index + 1, s1, s2));
	else if (s1[s1_index] != s2[s2_index])
		return (0);
	return (0);
}

int		match(char *s1, char *s2)
{
	return (match_rec(0, 0, s1, s2));
}
