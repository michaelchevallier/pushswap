/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:56:02 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 13:59:42 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		median_initializer(t_median **median, t_lman **list)
{
	*median = (t_median *)ft_memalloc(sizeof(t_lman));
	if (*median)
	{
		(*median)->median = 0;
		(*median)->tmp2 = (*list)->bot;
	}
}

void		median_initializer2(t_median **median, t_lman **list)
{
	(*median)->sup = 0;
	(*median)->inf = 0;
	(*median)->tmp = (*list)->bot;
	(*median)->median = (*median)->tmp2->value;
}

int			median_finder(t_lman **list)
{
	t_median	*median;

	median_initializer(&median, list);
	while (1)
	{
		median_initializer2(&median, list);
		while (median->tmp->next)
		{
			if (median->median < median->tmp->next->value)
				median->sup++;
			else
				median->inf++;
			median->tmp = median->tmp->next;
		}
		median->tmp2 = median->tmp2->next;
		if ((*list)->stack_size % 2 == 0)
		{
			if (median->sup == median->inf || median->sup + 1 == median->inf ||
					median->sup - 1 == median->inf)
				return (median->median);
		}
		else if (median->sup == median->inf)
			return (median->median);
	}
	return (median->median);
}
