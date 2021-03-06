/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 17:03:47 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 15:11:35 by mchevall         ###   ########.fr       */
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

void		print_actions2(t_stack *tmp)
{
	if (tmp->value == 7)
		ft_printf("rb");
	if (tmp->value == 8)
		ft_printf("rr");
	if (tmp->value == 9)
		ft_printf("rra");
	if (tmp->value == 10)
		ft_printf("rrb");
	if (tmp->value == 11)
		ft_printf("rrr");
	if (tmp->prev)
		ft_printf(" ");
}

void		print_actions(t_lman **retain, t_options **options)
{
	t_stack			*tmp;

	tmp = (*retain)->top;
	if ((*options)->color == 1)
		ft_putstr("\033[32m");
	while (tmp)
	{
		if (tmp->value == 1)
			ft_printf("sa");
		if (tmp->value == 2)
			ft_printf("sb");
		if (tmp->value == 3)
			ft_printf("ss");
		if (tmp->value == 4)
			ft_printf("pa");
		if (tmp->value == 5)
			ft_printf("pb");
		if (tmp->value == 6)
			ft_printf("ra");
		print_actions2(tmp);
		tmp = tmp->prev;
	}
	if ((*options)->color == 1)
		ft_putstr("\033[37m");
	ft_printf("\n");
}
