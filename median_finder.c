/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:56:02 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 18:26:22 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			median_finder(t_lman **list)
{
	int				median;
	int				sup;
	int				inf;
	t_stack			*tmp;
	t_stack			*tmp2;

	median = 0;
	tmp2 = (*list)->bot;
	while (1)
	{
		sup = 0;
		inf = 0;
		tmp = (*list)->bot;
		median = tmp2->value;
		while(tmp->next)
		{
			if (median < tmp->next->value)
				sup++;
			else
				inf++;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
		if ((*list)->stack_size % 2 == 0)
		{
			if (sup == inf || sup + 1 == inf || sup - 1 == inf)
				return (median);
		}
		else
		{
			if (sup == inf)
				return (median);
		}
	}
	return (median);
}
