/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:18:10 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 14:21:49 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_lman **list)
{
	t_stack		*tmp;

	if((*list)->stack_size <= 1)
		return ;
	tmp = (*list)->top;
	(*list)->top->prev->next = NULL;
	(*list)->top = (*list)->top->prev;
	tmp->next = (*list)->bot;
	tmp->prev = NULL;
	(*list)->bot->prev = tmp;
	(*list)->bot = tmp;
}

void		rrotate(t_lman **a, t_lman **b)
{
	rotate(a);
	rotate(b);
}

void		reverse_rotate(t_lman **list)
{
	t_stack		*tmp;

	if((*list)->stack_size <= 1)
		return ;
	tmp = (*list)->bot;
	(*list)->bot->next->prev = NULL;
	(*list)->bot = (*list)->bot->next;
	tmp->prev = (*list)->top;
	tmp->next = NULL;
	(*list)->top->next = tmp;
	(*list)->top = tmp;
}

void		rreverse_rotate(t_lman **a, t_lman **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
