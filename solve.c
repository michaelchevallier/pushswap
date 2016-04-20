/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:40:23 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 20:41:15 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			solve(t_lman **a, t_lman **b, t_lman **retain)
{
	size_t		tmp;


	tmp = 0;
	while ((*a)->stack_size != tmp)
	{
		tmp = (*a)->stack_size;
		splitter(a, b, retain);
		reverse_sort(a, b, retain);
		printf("\n\n");
		print_list(a);
		print_list(b);
		printf("\n\n");
	}
	if ((*a)->top->value > (*a)->bot->value)
		rotatea(a, retain);
	while ((*b)->stack_size > 0)
		pusha(a, b, retain);
	printf("\n\n");
	print_list(a);
	print_list(b);
	printf("\n\n");
	print_actions(retain);
	ft_printf("\n %ld", (*retain)->stack_size);

}

void			reverse_sort(t_lman **a, t_lman **b, t_lman **retain)
{
	int		median;
	int		i;

	median = median_finder(b);
	i = 0;
	while (!reverse_sort_checker(b))
	{
		if ((*b)->top->value >= median)
		{
			pusha(a, b, retain);
			if (i == 1)
			{
				if (((*a)->stack_size > 1) &&
						((*a)->top->value > (*a)->top->prev->value))
					swapa(a, retain);
			}
			i = 1;
		}
		else if ((*b)->top->value < (*b)->top->prev->value)
			swapb(b, retain);
		else if ((*b)->bot->value > (*b)->top->value)
			rotateb(b, retain);
		else
			reverse_rotateb(b, retain);
		printf("\n\n");
		print_list(b);
		printf("\n\n");
	}
}

void			splitter(t_lman **a, t_lman **b, t_lman **retain)
{
	int			median;
	int			even;
	int			half;

	median = median_finder(a);
	even = (((*a)->stack_size % 2) ? 0 : 1);
	half = ((*a)->stack_size / 2) - even ;
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
	printf("\n\n");
	print_list(a);
	print_list(b);
	printf("\n\n");
}
