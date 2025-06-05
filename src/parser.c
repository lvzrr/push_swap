/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:10:19 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/01 13:18:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_u8	lookup(t_vec *v, ssize_t n)
{
	size_t	i;

	i = 0;
	while (i < v->size)
		if (*(ssize_t *)ft_vec_get(v, i++) == n)
			return (1);
	return (0);
}

t_u8	eat(char *s, t_vec *v)
{
	char	**split;
	size_t	i;
	ssize_t	x;

	split = ft_split(s, ' ');
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		x = ft_atol(split[i++]);
		if (x > INT_MAX || x < INT_MIN || lookup(v, x))
			return (1);
		ft_vec_push(v, &x, 1);
		ft_free((void **)&split[i - 1]);
	}
	return (ft_free_array((void ***)&split), 0);
}
