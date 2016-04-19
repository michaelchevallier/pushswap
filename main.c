/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:32:45 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/19 18:18:19 by mchevall         ###   ########.fr       */
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
		print_list(&a);
		print_list(&b);
		push (&a ,&b);
		print_list(&a);
		print_list(&b);
		push (&b ,&a);
		print_list(&a);
		print_list(&b);
		push (&b ,&a);
		print_list(&a);
		print_list(&b);
		push (&b ,&a);
		print_list(&a);
		print_list(&b);
		push (&a ,&b);
		print_list(&a);
		print_list(&b);
	}
	return (0);
}
