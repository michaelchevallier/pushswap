/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:26:32 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 14:36:39 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_checker(t_lman **list)
{
	t_stack		*tmp;

	if ((*list)->stack_size == 0)
		return (0);
	if ((*list)->stack_size == 1)
		return (1);
	tmp = (*list)->bot;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			reverse_sort_checker(t_lman **list)
{
	t_stack		*tmp;

	if ((*list)->stack_size == 0)
		return (0);
	if ((*list)->stack_size == 1)
		return (1);
	tmp = (*list)->bot;
	while (tmp->next)
	{
		if(tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
