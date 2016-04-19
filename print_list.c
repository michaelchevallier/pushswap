/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:03:47 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/19 18:17:14 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_list(t_lman **list)
{
	t_stack			*tmp;

	tmp = (*list)->bot;
	if ((*list)->stack_size == 0)
		return ;
	while (tmp->next)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->value);
}
