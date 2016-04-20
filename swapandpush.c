/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapandpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:19:39 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 20:19:46 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swapa(t_lman **list, t_lman **retain)
{
	int		tmpvalue;

	if ((*list)->stack_size <= 1)
		return ;
	tmpvalue = (*list)->top->value;
	(*list)->top->value = (*list)->top->prev->value;
	(*list)->top->prev->value = tmpvalue;
	retainer(retain, 1);
}

void		swapb(t_lman **list, t_lman **retain)
{
	int		tmpvalue;

	if ((*list)->stack_size <= 1)
		return ;
	tmpvalue = (*list)->top->value;
	(*list)->top->value = (*list)->top->prev->value;
	(*list)->top->prev->value = tmpvalue;
	retainer(retain, 2);
}

void		sswap(t_lman **a, t_lman **b, t_lman **retain)
{
	swapa(a, retain);
	swapb(b, retain);
}

void		pusha(t_lman **a, t_lman **b, t_lman **retain)
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
	retainer(retain, 4);
}

void		pushb(t_lman **a, t_lman **b, t_lman **retain)
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
	retainer(retain, 5);
}
