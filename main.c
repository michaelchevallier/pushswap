/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:32:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 15:55:36 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_print(t_options **options, t_lman **a, t_lman **retain)
{
	if ((*options)->printoff != 1)
		print_actions(retain, options);
	if ((*options)->list == 1)
		print_list(a);
	if ((*options)->nbop == 1)
		ft_printf("%ld operations to sort this list", (*retain)->stack_size);
}

int			main(int argc, char **argv)
{
	t_lman		*a;
	t_lman		*b;
	t_lman		*retain;
	t_options	*options;
	int			arg;

	arg = 1;
	if (argc < 2)
		ft_error();
	else
	{
		options_initializer(&options);
		lman_initialiser(&a);
		lman_initialiser(&b);
		lman_initialiser(&retain);
		arg += check_options(argv, &options);
		list_maker(argc, argv, &a, arg);
		if (sort_checker(&a) == 1)
			return (0);
		solve(&a, &b, &retain);
		final_print(&options, &a, &retain);
	}
	return (0);
}
