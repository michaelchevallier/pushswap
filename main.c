/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:32:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 14:16:29 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_lman		*a;
	t_lman		*b;
	t_lman		*retain;
	int			arg;

	arg = 1;
	if (argc < 2)
		ft_error();
	else
	{
		lman_initialiser(&a);
		lman_initialiser(&b);
		lman_initialiser(&retain);
		list_maker(argc, argv, &a, arg);
		if (sort_checker(&a) == 1)
			return (0);
		else
			solve(&a, &b, &retain);
		print_actions(&retain);
		print_list(&a);
		ft_printf("%ld operations to sort this list", retain->stack_size);
	}
	return (0);
}
