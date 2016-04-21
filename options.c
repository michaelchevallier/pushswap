/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchevall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:30:27 by mchevall          #+#    #+#             */
/*   Updated: 2016/04/21 16:01:33 by mchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		options_initializer(t_options **options)
{
	(*options) = (t_options *)ft_memalloc(sizeof(t_options));
	(*options)->list = 0;
	(*options)->printoff = 0;
	(*options)->nbop = 0;
	(*options)->color = 0;
}

int			valid_options(char *str, t_options **options)
{
	if (str[0] == 'l')
		(*options)->list = 1;
	else if (str[0] == 'p')
		(*options)->printoff = 1;
	else if (str[0] == 'n')
		(*options)->nbop = 1;
	else if (str[0] == 'c')
		(*options)->color = 1;
	else if (str[0] != '\0')
		return (0);
	return (1);
}

int			check_options(char **argv, t_options **options)
{
	int			i;
	char		*str;

	i = 1;
	if (argv[1][0] == '-' && ft_isdigit(argv[1][1]) == 0)
	{
		while (argv[1][i])
		{
			if ((str = ft_strchr(OPTIONS, argv[1][i])) != NULL)
			{
				if (valid_options(str, options) == 0)
					return (0);
				i++;
			}
		}
	}
	else
		return (0);
	return (1);
}
