/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:25:17 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/19 16:06:57 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

typedef struct		s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
}					t_stack;

typedef struct		s_lman
{
	t_stack			*bot;
	t_stack			*top;
	size_t			stack_size;
}					t_lman;

void				ft_error(void);
void				lman_initialiser(t_lman **list);
void				stack_maker(t_stack **stack, int value);
void				stack_addbot(t_lman **list, t_stack *newstack);
void				list_destroyer(t_lman **list);
void				list_maker(int argc, char **argv, t_lman **a, int arg);
void				error_checker(char *str);
void				dual_checker(t_lman *a, int nbarg);
