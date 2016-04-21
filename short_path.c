/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:45:16 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 14:08:36 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			short_path(t_lman **list, int median)
{
	t_stack			*tmp;
	t_lman			*ltmp;
	int				rot;
	int				reverse;

	rot = 0;
	reverse = 0;
	tmp = (*list)->bot;
	ltmp = (*list);
	while (tmp->next)
	{
		if (tmp->value <= median)
			break ;
		reverse++;
		tmp = tmp->next;
	}
	tmp = (*list)->top;
	while (tmp->prev)
	{
		if (tmp->value <= median)
			break ;
		rot++;
		tmp = tmp->prev;
	}
	return ((rot >= reverse) ? -1 : 1);
}

int			reverse_short_path(t_lman **list, int median)
{
	t_stack			*tmp;
	t_lman			*ltmp;
	int				rot;
	int				reverse;

	rot = 0;
	reverse = 0;
	tmp = (*list)->bot;
	ltmp = (*list);
	while (tmp->next)
	{
		if (tmp->value != median)
			break ;
		reverse++;
		tmp = tmp->next;
	}
	tmp = (*list)->top;
	while (tmp->prev)
	{
		if (tmp->value != median)
			break ;
		rot++;
		tmp = tmp->prev;
	}
	return ((rot >= reverse) ? -1 : 1);
}
