/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:14:55 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/06 02:16:04 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_three(t_vec *a)
{
	ssize_t		x;
	ssize_t		y;
	ssize_t		z;

	x = *(ssize_t *)ft_vec_get(a, a->size - 3);
	y = *(ssize_t *)ft_vec_get(a, a->size - 2);
	z = *(ssize_t *)ft_vec_get(a, a->size - 1);
	if (x < y && y < z)
		return ;
	if (x < z && z < y)
		s(a, 1);
	else if (y < x && x < z)
		s(a, 1);
	else if (z < x && x < y)
		rrx(a, 1);
	else if (y < z && z < x)
		r(a, 1);
	else if (z < y && y < x)
	{
		s(a, 1);
		rrx(a, 1);
	}
}

void	sort_four(t_vec *a, t_vec *b)
{
	while (get_min(a) != a->size - 1)
		r(a, 1);
	p(b, a, 1);
	sort_three(a);
	p(a, b, 2);
}

void	sort_five(t_vec *a, t_vec *b)
{
	while (a->size > 3)
	{
		if (*(ssize_t *)ft_vec_peek_last(a)
			== *(ssize_t *)ft_vec_get(a, get_min(a)))
			p(b, a, 1);
		else
			r(a, 1);
	}
	sort_three(a);
	while (b->size)
		p(a, b, 2);
}

void	normalize_indices(t_vec *v)
{
	t_vec		sorted;
	ssize_t		val;
	ssize_t		rank;
	size_t		i;
	size_t		j;

	sorted = ft_vec(500, sizeof(ssize_t));
	ft_vec_push(&sorted, v->data, v->size);
	_sort_vec(&sorted);
	i = 0;
	while (i < v->size)
	{
		val = *(ssize_t *)ft_vec_get(v, i);
		j = 0;
		while (j < sorted.size)
		{
			if (*(ssize_t *)ft_vec_get(&sorted, j) == val)
				break ;
			j++;
		}
		rank = (ssize_t)j;
		ft_memcpy(ft_vec_get_mut(v, i), &rank, sizeof(ssize_t));
		i++;
	}
	ft_free(&sorted.data);
}
