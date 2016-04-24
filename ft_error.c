/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:44:30 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 13:38:10 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void		error_checker(char *str)
{
	intmax_t			i;

	i = 0;
	if (!str)
		ft_error();
	if (str[0] == '+' || str[0] == '-')
	{
		if (!str[1] || !ft_isdigit(str[1]))
			ft_error();
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_error();
		i++;
	}
	i = ft_intmaxatoi(str);
	if (i > 2147483647 || i < -2147483648)
			ft_error();
}

void		dual_checker(t_lman *a, int nbarg)
{
	t_stack		*tmp;
	int			*tab;
	int			i;
	int			j;

	i = -1;
	j = -1;
	tab = (int *)ft_memalloc(sizeof(int) * nbarg);
	tmp = a->bot;
	while (tmp && tab)
	{
		tab[++i] = tmp->value;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < nbarg && tab)
	{
		j = i + 1;
		while (++j < nbarg)
		{
			if (tab[i] == tab[j])
				ft_error();
		}
	}
	((tab) ? free(tab) : 0);
}
