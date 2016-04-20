/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retainer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 20:05:38 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 20:08:31 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		retainer(t_lman **retain, int value)
{
	t_stack		*holder;

	stack_maker(&holder, value);
	stack_addbot(retain, holder);
}
