/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:01:13 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/05 18:02:46 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline ssize_t	__min(ssize_t x, ssize_t y)
{
	if (x < y)
		return (x);
	return (y);
}

void	*get_min(t_vec *v)
{
	ssize_t	curr_min;
	size_t	min_index;
	size_t	i;
	ssize_t	value;

	if (!v || v->size == 0)
		return (NULL);
	curr_min = *(ssize_t *)ft_vec_get(v, 0);
	min_index = 0;
	i = 1;
	while (i < v->size)
	{
		value = *(ssize_t *)ft_vec_get(v, i);
		if (value < curr_min)
		{
			curr_min = value;
			min_index = i;
		}
		i++;
	}
	return (ft_vec_get_mut(v, min_index));
}
