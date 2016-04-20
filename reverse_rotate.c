/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:24:54 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 20:25:26 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse_rotatea(t_lman **list, t_lman **retain)
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
	retainer(retain, 9);
}

void		reverse_rotateb(t_lman **list, t_lman **retain)
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
	retainer(retain, 10);
}

void		rreverse_rotate(t_lman **a, t_lman **b, t_lman **retain)
{
	reverse_rotatea(a, retain);
	reverse_rotateb(b, retain);
}
