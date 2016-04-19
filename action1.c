/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:47:18 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/19 19:01:42 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_lman **list)
{
	int		tmpvalue;

	if ((*list)->stack_size <= 1)
		return ;

	print_list(list);
	tmpvalue = (*list)->top->value;
	(*list)->top->value = (*list)->top->prev->value;
	(*list)->top->prev->value = tmpvalue;
	print_list(list);
}

void		sswap(t_lman **a, t_lman **b)
{
	swap(a);
	swap(b);
}

void		push(t_lman **a, t_lman **b)
{
	t_stack		*tmp;

	if ((*b)->stack_size == 0)
		return ;
	tmp = (*b)->top;
	if ((*b)->top->prev)
	{
		(*b)->top = (*b)->top->prev;
		(*b)->top->next = NULL;
	}
	else
	{
		(*b)->top = NULL;
		(*b)->bot = NULL;
	}
	(*b)->stack_size--;
	if ((*a)->stack_size != 0)
		(*a)->top->next = tmp;
	tmp->prev = (*a)->top;
	(*a)->top = tmp;
	if ((*a)->stack_size == 0)
		(*a)->bot = tmp;
	(*a)->stack_size++;
}
