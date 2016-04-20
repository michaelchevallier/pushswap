/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 13:25:17 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/20 20:38:29 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

/* 1 = sa
 * 2 = sb
 * 3 = ss
 * 4 = pa
 * 5 = pb
 * 6 = ra
 * 7 = rb
 * 8 = rr
 * 9 = rra
 * 10 = rrb
 * 11 = rrr
 */

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
void				print_list(t_lman **list);
void				swapa(t_lman **list, t_lman **retain);
void				swapb(t_lman **list,t_lman **retain);
void				sswap(t_lman **a, t_lman **b, t_lman **retain);
void				pusha(t_lman **a, t_lman **b, t_lman **retain);
void				pushb(t_lman **a, t_lman **b, t_lman **retain);
void				rotatea(t_lman **list, t_lman **retain);
void				rotateb(t_lman **list, t_lman **retain);
void				rrotate(t_lman **a, t_lman **b, t_lman **retain);
void				reverse_rotatea(t_lman **list, t_lman **retain);
void				reverse_rotateb(t_lman **list, t_lman **retain);
void				rreverse_rotate(t_lman **a, t_lman **b, t_lman **retain);
void				solve(t_lman **a, t_lman **b, t_lman **remain);
void				splitter(t_lman **a, t_lman **b, t_lman **remain);
void				sort(t_lman **list);
void				reverse_sort(t_lman **a, t_lman **b, t_lman **remain);
int					sort_checker(t_lman **list);
int					reverse_sort_checker(t_lman **list);
int					median_finder(t_lman **list);
int					short_path(t_lman **list, int median);
void				retainer(t_lman **retain, int value);
void				print_actions(t_lman **retain);
