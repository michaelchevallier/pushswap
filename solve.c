/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:40:23 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 16:33:20 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			solve_mini(t_lman **a, t_lman **retain)
{
	while (sort_checker(a) != 1)
	{
		if (reverse_sort_checker(a) == 1)
			rotatea(a, retain);
		else if ((*a)->top->value > (*a)->bot->value)
			rotatea(a, retain);
		else if ((*a)->top->value > (*a)->top->prev->value)
			swapa(a, retain);
		else
			rotatea(a, retain);
	}
}

void			solve(t_lman **a, t_lman **b, t_lman **retain)
{
	size_t		tmp;
	int			median;

	median = median_finder(a);
	tmp = 0;
	if ((*a)->stack_size <= 3)
		solve_mini(a, retain);
	else if ((*a)->stack_size <= 20)
		sort(b, a, retain);
	else
	{
		splitter(a, b, retain);
		if ((*a)->top->value > (*a)->bot->value)
			rotatea(a, retain);
		sort(b, a, retain);
		sort(a, b, retain);
		while ((*b)->stack_size > 0)
			pusha(a, b, retain);
	}
}

void			sort(t_lman **a, t_lman **b, t_lman **retain)
{
	t_stack		*tmp;
	intmax_t	maxvalue;

	tmp = NULL;
	maxvalue = -999999999999999;
	while ((*b)->stack_size > 0)
	{
		tmp = (*b)->top;
		while (tmp)
		{
			if (maxvalue < tmp->value)
				maxvalue = tmp->value;
			tmp = tmp->prev;
		}
		if ((*b)->top->value == maxvalue)
			pusha(a, b, retain);
		else
		{
			if (reverse_short_path(b, maxvalue) == 1)
				reverse_rotateb(b, retain);
			else
				rotateb(b, retain);
		}
		maxvalue = -999999999999999;
	}
}

void			splitter(t_lman **a, t_lman **b, t_lman **retain)
{
	int			median;
	int			even;
	int			half;

	median = median_finder(a);
	even = (((*a)->stack_size % 2) ? 0 : 1);
	half = ((*a)->stack_size / 2) - even;
	while (half > 0)
	{
		if ((*a)->top->value <= median)
		{
			pushb(b, a, retain);
			half--;
			if (((*b)->stack_size > 1) &&
					((*b)->top->value < (*b)->top->prev->value))
				swapb(b, retain);
		}
		else
		{
			if (short_path(a, median) == 1)
				rotatea(a, retain);
			else
				reverse_rotatea(a, retain);
		}
	}
}
