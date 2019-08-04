/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:45:41 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/11 17:18:06 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		is_good(int *numbers, int length)
{
	int target;
	int index;
	int correct;

	target = 10 - length;
	index = length - 1;
	correct = 1;
	while (index > 0)
	{
		if (numbers[index - 1] + 1 != numbers[index])
		{
			correct = 0;
			break ;
		}
		index--;
	}
	if (correct == 1)
	{
		if (numbers[0] != target)
		{
			correct = 0;
		}
	}
	return (correct);
}

int		output(int *nums, int *current_index, int *display_index, int *n)
{
	while (nums[*current_index] <= 9)
	{
		*display_index = -1;
		while (++*display_index < *n)
			ft_putchar(nums[*display_index] + '0');
		if (is_good(nums, *n) == 0)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		else
			return (1);
		nums[*current_index]++;
	}
	nums[*current_index - 1]++;
	nums[*current_index] = nums[*current_index - 1] + 1;
	return (0);
}

void	ft_print_combn(int n)
{
	int nums[n];
	int done;
	int display_index;
	int current_index;
	int leading_number;

	display_index = -1;
	leading_number = 0;
	while (++display_index < n)
		nums[display_index] = 0;
	done = 0;
	while (done == 0)
	{
		nums[0] = leading_number;
		display_index = 0;
		while (++display_index < n)
			nums[display_index] = nums[display_index - 1] + 1;
		current_index = n - 1;
		while (nums[current_index - 1] <= 9 && done == 0)
		{
			done = output(nums, &current_index, &display_index, &n);
		}
		current_index--;
		leading_number++;
	}
}
