/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsiddiq <arsiddiq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:35:51 by arsiddiq          #+#    #+#             */
/*   Updated: 2019/07/24 23:32:14 by arsiddiq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sort_nodes(t_list **nodes, int size, int (*cmp)())
{
	t_list	*current;
	t_list	*comparable;
	t_list	*min;
	t_list	*temp;
	t_list	*prev;
	int first;

	first = 1;
	current = *nodes;
	while (current)
	{
		min = current;
		comparable = current->next;
		while (comparable)
		{
			if (cmp(comparable->data, min->data) < 0)
				min = comparable;
			comparable = comparable->next;
		}
		if (first)
		{
			first = 0;
			prev = (*nodes)->next;
			temp = *nodes;
			*nodes = min;
			min->next = temp;
			temp->next = prev;
		}
		else
		{
			temp = min->next;
			min->next = current;
			prev->next = min;
			current->next = temp;
		}
		prev = min;
		current = min->next;
	}
}


void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
/*	int amount;
	t_list *initial;

	initial = *begin_list;
	amount = 0;
	while (initial)
	{
		initial = initial->next;
		amount++;
	}
	ft_sort_nodes(begin_list, amount, cmp);
*/
	t_list	*head;
	t_list	*temp;
	t_list	*min;
	t_list	*r;
	void	*data;

	head = *begin_list;
	temp = head;
	while (temp)
	{
		min = temp;
		r = temp->next;
		while (r)
		{
			if (cmp(min->data, r->data) > 0)
			{
				min = r;
			}
			r = r->next;
		}
		data = temp->data;
		temp->data = min->data;
		min->data = data;
		temp = temp->next;
	}
}




		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>

		#define TEST(EXP, RES) printf(#EXP " (" #RES " vs %d) -> %d\n", (EXP), ((EXP)) == (RES))
		#define TEST_STR(EXP, RES) printf(#EXP " (" #RES " vs \"%s\") -> %d\n", (EXP), strcmp(((EXP)), (RES)) == 0)

	#include "ft_list.h"
void ft_list_sort(t_list **begin_list, int (*cmp)());
t_list* ft_create_elem(void* data)
{
	t_list* item = malloc(sizeof(t_list));
	item->next = NULL;
	item->data = data;
	return (item);
}
#define CE(data) ft_create_elem(data)
#define CL(list) crap_a_list(list)
// pronounced with an exclaimation point at the end
void crap_a_list(t_list* list)
{
	for (; list != 0; list = list->next)
		printf("%s,", (char*)list->data);
	printf("\n");
}
// pronounced with an exclaimation point at the end
t_list* crap_the_argv(char** argv)
{
	t_list* res = 0;
	t_list* tail = 0;
	argv++;
	while (*argv != 0)
	{
		if (tail == 0)
			res = tail = CE(*argv++);
		else
		{
			tail->next = CE(*argv++);
			tail = tail->next;
		}
	}
	return res;
}
void print_str(char* str)
{
	printf("%s\n", str);
}
int currents_with(char* str, char* ref)
{
	return str[0] - ref[0];
}
int main(int argc, char** argv)
{
	if (argc < 1)
		return 1;
	t_list* list = crap_the_argv(argv);
	ft_list_sort(&list, (int(*)())strcmp);
	crap_a_list(list);
}


