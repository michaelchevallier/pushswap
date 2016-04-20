/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:32:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 14:42:49 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_lman		*a;
	t_lman		*b;
	int			arg;

	arg = 1;

	if (argc < 2)
		ft_error();
	else
	{
		lman_initialiser(&a);
		lman_initialiser(&b);
		list_maker(argc, argv, &a, arg);
		if (sort_checker(&a) == 1)
			return (0);
		ft_printf("sort: %d\n", sort_checker(&a));
		ft_printf("sort: %d\n", reverse_sort_checker(&a));
		print_list(&a);
		print_list(&b);
		push (&b ,&a);
		print_list(&a);
		print_list(&b);
		swap (&a);
		print_list(&a);
		print_list(&b);
		push (&b ,&a);
		print_list(&a);
		print_list(&b);
		sswap (&a ,&b);
		print_list(&a);
		print_list(&b);
		rotate (&a);
		print_list(&a);
		print_list(&b);
		reverse_rotate(&b);
		print_list(&a);
		print_list(&b);
		rreverse_rotate(&a, &b);
		print_list(&a);
		print_list(&b);
		rrotate(&a, &b);
		print_list(&a);
		print_list(&b);
	}
	return (0);
}
