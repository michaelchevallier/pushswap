/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:18:10 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 14:07:02 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotatea(t_lman **list, t_lman **retain)
{
	t_stack		*tmp;

	if ((*list)->stack_size <= 1)
		return ;
	tmp = (*list)->top;
	(*list)->top->prev->next = NULL;
	(*list)->top = (*list)->top->prev;
	tmp->next = (*list)->bot;
	tmp->prev = NULL;
	(*list)->bot->prev = tmp;
	(*list)->bot = tmp;
	retainer(retain, 6);
}

void		rotateb(t_lman **list, t_lman **retain)
{
	t_stack		*tmp;

	if ((*list)->stack_size <= 1)
		return ;
	tmp = (*list)->top;
	(*list)->top->prev->next = NULL;
	(*list)->top = (*list)->top->prev;
	tmp->next = (*list)->bot;
	tmp->prev = NULL;
	(*list)->bot->prev = tmp;
	(*list)->bot = tmp;
	retainer(retain, 7);
}

void		rrotate(t_lman **a, t_lman **b, t_lman **retain)
{
	rotatea(a, retain);
	rotateb(b, retain);
}
