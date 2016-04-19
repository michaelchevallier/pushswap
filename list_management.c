/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:42:26 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/19 15:52:40 by mchevall         ###   ########.fr       */
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

void		stack_maker(t_stack **stack, int value)
{
	*stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	if (*stack)
	{
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->value = value;
	}
}

void		stack_addbot(t_lman **list, t_stack *new_stack)
{
	if (!(*list)->top)
		(*list)->top = new_stack;
	else
	{
		(*list)->bot->prev = new_stack;
		new_stack->prev = NULL;
		new_stack->next = (*list)->bot;
	}
	(*list)->bot = new_stack;
	(*list)->stack_size++;
}

void		list_destroyer(t_lman **list)
{
	t_stack		*tmp;

	tmp = NULL;
	while ((*list)->bot != NULL)
	{
		tmp = (*list)->bot->next;
		free((*list)->bot);
		(*list)->bot = tmp;
	}
	(*list)->bot = NULL;
	(*list)->top = NULL;
	free(list);
}

void		list_maker(int argc, char **argv, t_lman **a, int arg)
{
	t_stack		*stack;
	int			tmp;

	tmp = arg;
	while (arg < argc)
	{
		error_checker(argv[arg]);
		stack_maker(&stack, ft_atoi(argv[arg]));
		stack_addbot(a, stack);
		arg++;
	}
	dual_checker(*a, argc - tmp);
}
