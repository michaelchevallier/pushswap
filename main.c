/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:32:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/18 14:42:01 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		lman_initialiser(t_lman **list_manager)
{
	*list_manager = (t_lman *)ft_memalloc(sizeof(t_lman));
	(*list_manager)->tail = NULL;
	(*list_manager)->head = NULL;
}

int			main(int argc, const char **argv)
{
	t_stack		*tmp;
	t_lman		*list_manager;
	int			stack_size;

	stack_size = 1;
	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	lman_initialiser(&list_manager);
	if (argc < 2)
		ft_error();
	else
	{
		while (stack_size != argc - 1)
		{
			if (tmp)
				stack->prev = stack;
			tmp = (t_stack *)ft_memalloc(sizeof(t_stack));
			stack->value = ft_atoi(argv[stack_size]);
			stack->next = tmp;
			stack_size++;
		}
	}
	return 0;
}
