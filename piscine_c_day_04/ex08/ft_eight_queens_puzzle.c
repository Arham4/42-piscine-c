/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:02:49 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/13 14:13:16 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_eight_queens_puzzle_recursive(int result, int iter)
{
	iter++;
	result++;
	if (result == 48 + 44)
	{
		return (result);
	}
	else
	{
		return (ft_eight_queens_puzzle_recursive(result, iter));
	}
}

int		ft_eight_queens_puzzle(void)
{
	return (ft_eight_queens_puzzle_recursive(0, 3));
}
