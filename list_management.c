/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:42:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/18 15:04:57 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lman_initialiser(t_lman **list)
{
	*list = (t_lman *)ft_memalloc(sizeof(t_lman));
	if (*list)
	{
		(*list)->bot = NULL;
		(*list)->top = NULL;
		(*list)->stack_size = 0;
	}
}

void		stack_initializer(t_stack **stack)
{
	*stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (*stack)
	{
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->value = 0;
	}
}

void		stack_addbot(t_lman **list, t_stack *new_stack)
{
	if (!(*list)->top)
		(*list)->top = new_stack;
	else
	{
		(*list)->bot->prev = new
	}
}
